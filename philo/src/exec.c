#include "../includes/philo.h"


int helper(t_info *ps)
{
    int i;

    i = 0;
    if (pthread_mutex_lock(ps->death_block) != 0)
        exit(printf("Lock Failed")); 
    // printf("%i helper death %i %p\n", ps->id + 1, *ps->death_state, ps->death_state);
    if (*(ps->death_state) != 0)
        i = 1;
    pthread_mutex_unlock(ps->death_block);
    // printf("helper %i\n", i);
    return (i);
}

void philosopher(void *v)
{
    t_info *ps;
    int i = -1;
    long t;

    ps = (t_info *)v;
    if (pthread_mutex_lock(ps->start) != 0)
        exit(printf("Lock Failed"));
    t = current_t();
    ps->start_time = t;
    pthread_mutex_lock(ps->last_eat_lock);
    ps->last_eat = t;
    pthread_mutex_unlock(ps->last_eat_lock);
    pthread_mutex_unlock(ps->start);
    if ((ps->id + 1) % 2 == 1)
    {
        thinking(ps);
        ft_usleep(100);
    }
    while (helper(ps) == 0)
    {
        eating(ps);
        sleeping(ps);
        thinking(ps);
    }
}

void    thinking(t_info *ps)
{
    print(ps, 't');
}

void    sleeping(t_info *ps)
{
    print(ps, 's');
    ft_usleep(ps->sleep);
}

void    eating(t_info *ps)
{
    pick_up(ps);
    put_down(ps);
}

void    pick_up(t_info *ps)
{
    t_forks *f;
    int     num;

    f = (t_forks *)ps->forks;
    num = ps->num;
    if (even_odd(ps->id) == 0)
    {
        if (pthread_mutex_lock(&f->forks[ps->id]) != 0)
            exit(printf("Lock Failed"));
        if (pthread_mutex_lock(&f->forks[(ps->id + 1) % num]) != 0)
            exit(printf("Lock Failed"));
    }
    else
    {
        if (pthread_mutex_lock(&f->forks[(ps->id + 1) % num]) != 0)
            exit(printf("Lock Failed"));
        if (pthread_mutex_lock(&f->forks[ps->id]) != 0)
            exit(printf("Lock Failed"));
    }
    print(ps, 'f');
}

void    put_down(t_info *ps)
{
    t_forks *f;
    int     num;
    
    f = (t_forks *)ps->forks;
    num = ps->num;
    print(ps, 'e');
    ft_usleep(ps->eat);
    if (even_odd(ps->id) == 0)
    {
        pthread_mutex_unlock(&f->forks[(ps->id + 1) % num]);
        pthread_mutex_unlock(&f->forks[ps->id]);
    }
    else
    {
        pthread_mutex_unlock(&f->forks[ps->id]);
        pthread_mutex_unlock(&f->forks[(ps->id + 1) % num]);
    }
    if (pthread_mutex_lock(ps->last_eat_lock) != 0)
        exit(printf("Lock Failed"));
	ps->last_eat = current_t();
    pthread_mutex_unlock(ps->last_eat_lock);
}
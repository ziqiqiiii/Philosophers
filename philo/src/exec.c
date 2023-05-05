#include "../includes/philo.h"

void *philosopher(void *v)
{
    t_info *ps;
    int i = -1;
    long t;

    ps = (t_info *)v;
    pthread_mutex_lock(ps->death_block);
    t = current_t();
    ps->start_time = t;
    ps->last_eat = t;
    pthread_mutex_unlock(ps->death_block);
    if ((ps->id + 1) % 2 == 1)
    {
        thinking(ps);
        ft_usleep(100);
    }
    while (++i < 5)
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
        pthread_mutex_lock(&f->forks[ps->id]);
        pthread_mutex_lock(&f->forks[(ps->id + 1) % num]);
    }
    else
    {
        pthread_mutex_lock(&f->forks[(ps->id + 1) % num]);
        pthread_mutex_lock(&f->forks[ps->id]);
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
	ps->last_eat = current_t();
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
}
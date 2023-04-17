#include "../includes/philo.h"

void *philosopher(void *v)
{
    t_info *ps;
    int i = -1;

    ps = (t_info *)v;
    while (++i < ps->num)
    {
        thinking(ps);
        eating(ps);
        sleeping(ps);
    }
}  

void    thinking(t_info *ps)
{
    print(ps, 't');
}

void    sleeping(t_info *ps)
{
    usleep(ps->sleep * 1000);
    print(ps, 's');
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
    if (even_odd(ps->id + 1) == 0)
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
    usleep(ps->eat * 1000);
    print(ps, 'e');
	ps->last_eat = current_t() + ps->eat;
    if (even_odd(ps->id + 1) == 0)
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
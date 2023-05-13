#include "../includes/philo.h"

t_info  *pthreadjoin(t_info *ps)
{
    int i;

    i = -1;
    // printf("nummmmm? %li\n", ps[1].eat);
    // printf("pthreadjoin %i %p\n", *ps->death_state, ps->death_state);
    while (++i < ps->num)
    {
        if (pthread_join(ps[i].philos, NULL) != 0)
        {
            printf("\nError joining the threads\n");
            exit(1);
        }
    }
    return (ps);
}

void    mutexdestroy(t_info *ps)
{
    int i;

    i = -1;
    while (++i < ps->num)
    {
        if (pthread_mutex_destroy(&ps->forks->forks[i]) != 0)
        {
            printf("\nError Mutex Destroyed\n");
            exit(1);
        }
    }
    if (pthread_mutex_destroy(ps->print) != 0)
    {
        printf("\nError Mutex Destroyed\n");
        exit(1);
    }
    // if (pthread_mutex_destroy(ps->death_block) != 0)
    // {
    //     printf("\nError Mutex Destroyed\n");
    //     exit(1);
    // }
    if (pthread_mutex_destroy(ps->last_eat_lock) != 0)
    {
        printf("\nError Mutex Destroyed\n");
        exit(1);
    }
}
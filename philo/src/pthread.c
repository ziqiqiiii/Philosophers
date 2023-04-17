#include "../includes/philo.h"

t_info  *pthreadjoin(t_info *ps)
{
    int i;

    i = -1;
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

t_info  *mutexdestroy(t_info *ps)
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
}
#include "../includes/philo.h"

void    free_all(t_info **ps)
{
    int i;
    int num;
    t_forks *f;

    i = 0;
    num = ps[0]->num;
    f = ps[0]->forks;
    free(f->forks);
    free(f);
    free(ps[0]->print);
    free(ps[0]->death_block);
    free(ps[0]->last_eat_lock);
    while (i < num)
    {
        free((void *)ps[i]->philos);
        i++;
    }
    i = 0;
    while (i < num)
    {
        free(ps[i]);
        i++;
    }
}
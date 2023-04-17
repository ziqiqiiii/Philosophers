#include "../includes/philo.h"

void    print(t_info *ps, int c)
{
    long t;

    char    *colour;

    if (ps->id + 1 == 1)
        colour = RED;
    else
        colour = NC;
    
    pthread_mutex_lock(ps->block);
    t = current_t();
    if (c == 't')
        printf("%s%ld %d is thinking%s\n", colour, t - ps->start_time, ps->id + 1, NC);
    else if (c == 'e')
        printf("%s%ld %d is eating%s\n", colour, t - ps->start_time, ps->id + 1, NC);
    else if (c == 's')
        printf("%s%ld %d is sleeping%s\n", colour, t - ps->start_time, ps->id + 1, NC);
    else if (c == 'f')
    {
        printf("%s%ld %d has taken fork %i\n%s", colour, t - ps->start_time, ps->id + 1, ps->id + 1, NC);
        printf("%s%ld %d has taken fork %i\n%s", colour, t - ps->start_time, ps->id + 1, ((ps->id + 1) % ps->num) + 1, NC);
    }
    pthread_mutex_unlock(ps->block);
}
#include "../includes/philo.h"

char *choose_colour(int id)
{
    if (id == 2)
        return (RED);
    else if (id == 3)
        return (YELLOW);
    else if (id == 4)
        return (BLUE);
    else if (id == 5)
        return (GREEN);
    else if (id == 6)
        return (PINK);
    else
        return (NC);
}

void    print(t_info *ps, int c)
{
    long t;
    char    *colour;

    colour = choose_colour(ps->id + 1);
    pthread_mutex_lock(ps->print);
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
    pthread_mutex_unlock(ps->print);
}
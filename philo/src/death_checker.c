#include "../includes/philo.h"

void death_checker(t_info *ps)
{
    int i;
    int num;
    long t;
    int a;

    i = 0;
    a = 1;
    while (a == 1)
    {
        pthread_mutex_lock(ps[i].death_block);
        num = ps[0].num;
        if (i + 1 >= ps[0].num)
            i = 0;
        if (current_t() - ps[i].last_eat >= ps[i].die)
        {
            ps[i].death_state = 1;
            a = 0;
        }
        printf("\n%i %li time taken \n death time %li\n", ps[i].id + 1, current_t() - ps[i].last_eat, ps[i].die);
        pthread_mutex_unlock(ps[i].death_block);
        ft_usleep(100);
        i++;
    }
}
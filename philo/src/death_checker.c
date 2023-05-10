#include "../includes/philo.h"

void death_checker(t_info *ps)
{
    int i;
    long t;
    long    lasteat_t;

    i = 0;
    while (1)
    {
        if (i + 1 > ps[0].num)
            i = 0;
        pthread_mutex_lock(ps[i].last_eat_lock);
        lasteat_t = ps[i].last_eat;
        // pthread_mutex_unlock(ps[i].last_eat_lock);
        // pthread_mutex_lock(ps[i].last_eat_lock);
        t = current_t();
        printf("\n%i %li time taken \n death time %li\n", ps[i].id + 1, t - ps[i].last_eat, ps[i].die);
        if (t - lasteat_t >= ps[i].die)
        {
            pthread_mutex_unlock(ps[0].last_eat_lock);
            pthread_mutex_lock(&ps[i].death_block[i]);
            *ps[i].death_state = 1;
            pthread_mutex_unlock(&ps[i].death_block[i]);
            break ;
        }
        pthread_mutex_unlock(ps[i].last_eat_lock);
        ft_usleep(100);
        i++;
    }
}

//
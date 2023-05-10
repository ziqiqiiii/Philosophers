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
        if (pthread_mutex_lock(ps[i].last_eat_lock) != 0)
            exit(printf("Lock Failed"));
        lasteat_t = ps[i].last_eat;
        pthread_mutex_unlock(ps[i].last_eat_lock);
        t = current_t();
        // printf("\n%i %li time taken \n death time %li\n", ps[i].id + 1, t - ps[i].last_eat, ps[i].die);
        if (t - lasteat_t >= ps[i].die)
        {
            if (pthread_mutex_lock(ps[i].death_block) != 0)
                exit(printf("Lock Failed"));
            *(ps[i].death_state) = 1;
            if (pthread_mutex_unlock(ps[i].death_block) != 0)
                exit(printf("Unlock Failed"));
            break ;
        }
        ft_usleep(100);
        i++;
    }
}

//
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
        printf("\n%i % li time taken \n death time %li\n", ps[i].id + 1, t - lasteat_t, ps[i].die);
        if (t - lasteat_t > ps[i].die)
        {   
            if (pthread_mutex_lock(ps[i].death_block) != 0)
                exit(printf("Lock Failed"));
            *ps[i].death_state = 1;
            print(ps, 'd');
            printf("death %i \n", ps[i].id + 1);
            if (pthread_mutex_unlock(ps[i].death_block) != 0)
                exit(printf("Unlock Failed"));
            break ;
        }
        ft_usleep(10);
        i++;
    }
}

int	before_eat_or_sleep(t_info *ps, int c)
{
	long	t;
    int		i;

	t = current_t();
	i = 0;
    if (c == 'e')
    {
        if (t + ps->eat > t + ps->die)
        {
            if (pthread_mutex_lock(ps->death_block) != 0)
                    exit(printf("Lock Failed"));
            *ps->death_state = 1;
            printf("makan %i die here\n", ps->id + 1);
            print(ps, 'd');
            if (pthread_mutex_unlock(ps->death_block) != 0)
                    exit(printf("Unlock Failed"));
            i = 1;
	    }
    }
	else if (c == 's')
    {
        if (t + ps->sleep > t + ps->die)
        {
            if (pthread_mutex_lock(ps->death_block) != 0)
                    exit(printf("Lock Failed"));
            *ps->death_state = 1;
            printf("sleep  %i die here\n", ps->id + 1);
            print(ps, 'd');
            if (pthread_mutex_unlock(ps->death_block) != 0)
                    exit(printf("Unlock Failed"));
            i = 1;
        }
    }
	return (i);
}
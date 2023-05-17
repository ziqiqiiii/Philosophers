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
        // printf("\n%i % li time taken \n death time %li\n", ps[i].id + 1, t - lasteat_t, ps[i].die);
        if (t - lasteat_t >= ps[i].die)
        {   
            if (pthread_mutex_lock(ps[i].death_block) != 0)
                exit(printf("Lock Failed"));
            *ps[i].death_state = 1;
            print_death(ps, ps[i].id + 1);
            // printf("death %i %p\n", *ps[i].death_state, ps[i].death_state);
            if (pthread_mutex_unlock(ps[i].death_block) != 0)
                exit(printf("Unlock Failed"));
            break ;
        }
        ft_usleep(100);
        i++;
    }
}

int	before_eat_or_sleep(t_info *ps, int c)
{
	long t;

	t = current_t();
    if (c == 'e')
    {
        if (t + ps->eat > t + ps->die)
        {
            if (pthread_mutex_lock(ps->death_block) != 0)
                    exit(printf("Lock Failed"));
            *ps->death_state = 1;
            // printf("%ld makan %i die here\n", t - ps->start_time, ps->id + 1);
            print_death(ps, ps->id + 1);
            if (pthread_mutex_unlock(ps->death_block) != 0)
                    exit(printf("Unlock Failed"));
            return (1);
	    }
    }
	else if (c == 's')
    {
        if (t + ps->sleep > t + ps->die)
        {
            if (pthread_mutex_lock(ps->death_block) != 0)
                    exit(printf("Lock Failed"));
            *ps->death_state = 1;
            print_death(ps, ps->id + 1);
            // printf("%ld sleep  %i die here\n", t - ps->start_time, ps->id + 1);
            if (pthread_mutex_unlock(ps->death_block) != 0)
                    exit(printf("Unlock Failed"));
            return (1);
        }
    }
	else
		return (0);
}
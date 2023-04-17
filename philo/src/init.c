#include "../includes/philo.h"

t_forks *initialize_fork(int num)
{
    t_forks *f;
    int     i;

    f = (t_forks *)malloc(sizeof(t_forks));
    f->num = num;
    i = 0;
    f->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
    while (i < num)
    {
        pthread_mutex_init(&f->forks[i], NULL);
        i++;
    }
    return (f);
}

long    current_t()
{
    struct timeval t;

    gettimeofday(&t, NULL);
    return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

t_info *initialize(int argc, char **argv)
{
    t_info *ps;
    t_forks *forks;
    int     num;
    int     i;
    int     *j;
    long    sleep;
    long    die;
    long    eat;
    int     min_eat;
    long    t;
    pthread_mutex_t *block;

    num = ft_atoi(argv[1]);
    die = ft_atoi(argv[2]);
    eat = ft_atoi(argv[3]);
    sleep = ft_atoi(argv[4]);
    if (argc == 6)
        min_eat = ft_atoi(argv[5]);
    else
        min_eat = 0;
    ps = (t_info *)malloc(sizeof(t_info) * num);
    forks = initialize_fork(num);
    block = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(block, NULL);
    i = -1;
    while (++i < num)
    {
        ps[i].philos = (pthread_t)malloc(sizeof(pthread_t));
        ps[i].forks = forks;
        ps[i].id = i;
        ps[i].num = num;
        ps[i].sleep = sleep;
        ps[i].die = die;
        ps[i].min_eat = min_eat;
        ps[i].die_state = 0;
        t = current_t();
        ps[i].start_time = t;
        ps[i].last_eat = t;
        ps[i].block = block;
        if (pthread_create(&ps[i].philos, NULL, (void *)philosopher, (void *)(ps + i)) != 0)
        {
            printf("\nThread creation error\n");
            exit (1);
        }
    }
    return(ps);
}
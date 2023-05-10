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

void    init_mutex(t_info *ps, int num)
{
    int i;
    pthread_mutex_t *print;
    pthread_mutex_t *death_block;
    pthread_mutex_t *last_eat_lock;
    pthread_mutex_t *death_checker;
	pthread_mutex_t	*start;

    i = -1;
    print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(print, NULL);
    death_block = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
    last_eat_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(last_eat_lock, NULL);
    death_checker = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(death_checker, NULL);
	start = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(start, NULL);
    while (++i < num)
    {
        ps[i].print = print;
        pthread_mutex_init(&death_block[i], NULL);
        ps[i].last_eat_lock = last_eat_lock;
        ps[i].death_checker = death_checker;
		ps[i].start = start;
    }
    i = -1;
    while (++i < num)
        ps[i].death_block = death_block;
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
    int		death_state;

    num = ft_atoi(argv[1]);
    die = ft_atoi(argv[2]);
    eat = ft_atoi(argv[3]);
    sleep = ft_atoi(argv[4]);
	death_state = 0;
    if (argc == 6)
        min_eat = ft_atoi(argv[5]);
    else
        min_eat = -1;
    ps = (t_info *)malloc(sizeof(t_info) * num);
    forks = initialize_fork(num);
    init_mutex(ps, num);
    i = -1;
    while (++i < num)
    {
        ps[i].philos = (pthread_t)malloc(sizeof(pthread_t));
        ps[i].forks = forks;
        ps[i].id = i;
        ps[i].num = num;
        ps[i].sleep = sleep;
        ps[i].die = die;
        ps[i].eat = eat;
        ps[i].min_eat = min_eat;
        ps[i].death_state = &death_state;
        if (pthread_create(&ps[i].philos, NULL, (void *)philosopher, (void *)(ps + i)) != 0)
        {
            printf("\nThread creation error\n");
            exit (1);
        }
    }
    return(ps);
}
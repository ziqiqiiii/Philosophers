#include "../includes/philo.h"

void *func(t_info *a)
{
    t_info left;
    t_info right;

    left = a[0];
    right = a[1];   
    printf("\nPhilosopher %d is thinking\n", left.i);
    pthread_mutex_lock(&left.forks);
    pthread_mutex_lock(&right.forks);
    printf("\nPhilosopher %d is eating\n",left.i);
    printf("\n%i && %i forks in use\n", left.i, right.i);
    // usleep(100);
    sleep(2);
    pthread_mutex_unlock(&left.forks);
    pthread_mutex_unlock(&right.forks);
    printf("\nPhilosopher %d Finished eating\n",left.i);
}

t_info *initialize(int argc, char **argv)
{
    int     num;
    t_info  *result;
    int     i;

    num = ft_atoi(argv[1]);
    result = malloc(sizeof(t_info) * num);
    i = 0;
    while (i < num)
    {
        result[i].philos = (pthread_t)malloc(sizeof(pthread_t));
        if (pthread_mutex_init(&result[i].forks, NULL) != 0)
        {
            printf("\n MUtex initialization failed\n");
            exit (1);
        }
        result[i].i      = i + 1;
        result[i].num    = num;
        i++;
    }
    return(result);

}

int main(int argc, char **argv)
{
    t_info  *a;
    t_info  b[2];
    int     num;
    int     i;
    int     j;

    i = 0;
    if (argc == 4 || argc == 5)
    {
        num = ft_atoi(argv[1]);
        a = initialize(argc, argv);
        i = 0;
        while (i < num)
        {
            b[0] = a[i];
            b[1] = a[(i + 1) % num];
            // printf("%i && philo num %i && %i\n", i, a[i].i, a[(i + 1) % num].i);
            j = pthread_create(&a[i].philos, NULL, (void *)func, b);
            if (j != 0)
            {
                printf("\n Thread creation error\n");
                exit (1);
            }
            i++;
        }
        i = 0;
        while (i < num)
        {
            if (pthread_join(a[i].philos, NULL) != 0)
            {
                printf("\n Error joining the threads\n");
                exit(1);
            }
            i++;
        }
        i = 0;
        while (i < num)
        {
            if (pthread_mutex_destroy(&a[i].forks) != 0)
            {
                printf("\n Mutex Destroyed\n");
                exit (1);
            }
            // free((void *)a[i].philos);
            i++;
        }
        return (0);
    }
    else
        printf("Error: wrong numbers of arguement\n");
} 
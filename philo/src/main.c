#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_info  *ps;
    int     i;

    if (error_check(argc, argv) == -1)
    {
        ft_putstr_fd("Error: wrong numbers of arguement\n", 2);
        exit(1);
    }
    ps = initialize(argc, argv);
    death_checker(ps);
    ps = pthreadjoin(ps);
    mutexdestroy(ps);
    // free_all(&ps);
} 
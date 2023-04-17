#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_info  *ps;
    int     i;

    if (argc == 5 || argc == 6)
    {
        ps = initialize(argc, argv);
        ps = pthreadjoin(ps);
        ps = mutexdestroy(ps);
        return (0);
    }
    else
    {
        ft_putstr_fd("Error: wrong numbers of arguement\n", 2);
        exit(1);
    }
}
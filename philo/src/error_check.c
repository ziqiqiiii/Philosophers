#include "../includes/philo.h"

int error_check(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
        return (-1);
    if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0 \
        || ft_atoi(argv[3]) == 0 || ft_atoi(argv[4]) == 0)
        return (-1);
    return (0);
}
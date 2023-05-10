#include "../includes/philo.h"

int ft_strlen(char *s)
{
    if (*s == '\0')
        return (0);
    return (ft_strlen(s + 1) + 1);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (a < n)
	{
		if (s1[a] != '\0' && (s1[a] == s2[a]))
			a++;
		else
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	result *= negative;
	return (result);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_usleep(int ms)
{
	long	t;

	t = current_t();
	while (1)
	{
		if (current_t() - t >= ms)
			break;
		usleep(100);
	}

}

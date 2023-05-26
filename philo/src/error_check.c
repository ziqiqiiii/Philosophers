/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:51 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/26 16:48:54 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_check(int argc, char **argv)
{
	int i;
	int	a;

	if (argc != 5 && argc != 6)
		return (-1);
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			return (-1);
		}
		a = 0;
		while (argv[i][a])
		{
			if (ft_isdigit(argv[i][a]) == 0)
				return (-1);
			a++;
		}
		i++;
	}
	return (0);
}

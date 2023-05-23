/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:51 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 19:43:40 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0 \
		|| ft_atoi(argv[3]) == 0 || ft_atoi(argv[4]) == 0)
		return (-1);
	return (0);
}

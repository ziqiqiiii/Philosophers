/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:54 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 19:44:16 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	even_odd(int i)
{
	if (i == 0)
		return (0);
	else if (i % 2 == 0)
		return (0);
	else
		return (1);
}

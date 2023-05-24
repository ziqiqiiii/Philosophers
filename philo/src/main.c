/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:13 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 15:11:21 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*ps;

	if (error_check(argc, argv) == -1)
		exit(printf("Error: wrong numbers of arguement"));
	ps = initialize(argc, argv);
	checker(ps);
	pthreadjoin(ps);
	mutexdestroy(ps);
	// system("leaks philo");
}

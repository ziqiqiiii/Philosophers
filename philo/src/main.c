/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:13 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 15:40:31 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    pthreadjoin(ps);
    mutexdestroy(ps);
    // free_all(&ps);
} 
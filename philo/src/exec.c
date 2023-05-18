/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 16:41:25 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void philosopher(void *v)
{
    t_info *ps;

    ps = (t_info *)v;
    start(ps);
    if ((ps->id + 1) % 2 == 1)
    {
        thinking(ps);
        ft_usleep(ps->eat);
    }
    while (helper(ps) == 0)
    {
        eating(ps);
        if (helper(ps) != 0)
            break ;
        sleeping(ps);
        if (helper(ps) != 0)
            break ;
        thinking(ps);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:04 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 14:58:05 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    free_all(t_info **ps)
{
    int i;
    int num;
    t_forks *f;

    i = 0;
    num = ps[0]->num;
    f = ps[0]->forks;
    free(f->forks);
    free(f);
    free(ps[0]->print);
    free(ps[0]->death_block);
    free(ps[0]->last_eat_lock);
    while (i < num)
    {
        free((void *)ps[i]->philos);
        i++;
    }
    i = 0;
    while (i < num)
    {
        free(ps[i]);
        i++;
    }
}
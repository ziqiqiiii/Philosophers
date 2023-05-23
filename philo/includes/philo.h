/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:55:35 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 20:25:26 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_forks
{
	pthread_mutex_t	*forks;
}	t_forks;

typedef struct s_mutex
{
	pthread_mutex_t	print;
	pthread_mutex_t	death_block;
	pthread_mutex_t	last_eat_lock;
	pthread_mutex_t	eaten;
	pthread_mutex_t	eat_flag;
}	t_mutex;

typedef struct s_info
{
	pthread_t	*philos;
	t_forks		*forks;
	int			id;
	int			num;
	long		sleep;
	long		die;
	long		eat;
	int			min_eat;
	int			eaten;
	int			*eat_flag;
	int			*death_state;
	long		start_time;
	long		death_time;
	t_mutex		*mutex;
}	t_info;

# define RED "\033[031m"
# define GREEN "\033[032m"
# define YELLOW "\033[033m"
# define BLUE "\033[034m"
# define PINK "\033[035m"
# define TEAL "\033[036m"
# define WHITE "\033[037m"
# define NC "\033[0m"
# define PEACH "\x1b[38;2;255;218;185m"

# define BOLD "\033[1m"

//utils.c
int		ft_atoi(const char *str);
void	ft_usleep(int ms);

//even-odd
int		even_odd(int i);

//init.c
void	initialize_fork(int num, t_info *ps);
t_info	*initialize(int argc, char **argv);

//exec.c
void	philosopher(void *v);

//current_t.c
long	current_t(void);

//eat_sleep_think.c
void	sleeping(t_info *ps);
void	thinking(t_info *ps);
void	eating(t_info *ps);
void	pick_up(t_info *ps);
void	put_down(t_info *ps);

//pthread.c
void	pthreadjoin(t_info *ps);
void	mutexdestroy(t_info *ps);

//print.c
void	print(t_info *ps, int c);

//error_check.c
int		error_check(int argc, char **argv);

//death_checker.c
void	death_checker(t_info *ps);
int		before_sleep(t_info *ps);
int		before_eat(t_info *ps);
int		helper(t_info *ps);

//ft_mutex.c
void	ft_pthread_mutex_lock(pthread_mutex_t *c);
void	ft_pthread_mutex_unlock(pthread_mutex_t *c);
void	ft_pthread_mutex_destroy(pthread_mutex_t *c);
void	ft_pthread_join(pthread_t *philo);

#endif
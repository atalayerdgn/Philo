/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:19 by aerdogan          #+#    #+#             */
/*   Updated: 2024/01/18 01:02:08 by aerdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_table
{
	uint64_t		time_to_sleep;
	uint64_t		time_to_eat;
	uint64_t		time_to_dead;
	uint64_t		start_time;
	uint64_t		lasttime;
	int				nbr_philos;
	int				wanted_meals;
	int				*fork;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	is_die;
	pthread_mutex_t	is_ate;
}				t_table;

typedef struct s_philo
{
	int			id;
	pthread_t	*philo;
	t_table		*data;
}				t_philo;

typedef enum s_errphilo
{
	SET_DATA,
	INIT_MUTEX,
	SET_PHILO,
	CREATE_THREAD
}			t_errphilo;

typedef enum s_errno
{
	TRUE = 50,
	FALSE
}			t_errno;

u_int64_t	ft_atoi(char *str);
uint64_t	gettime(void);
int 		set_data(t_philo *philo, t_table *data, int ac, char **av);
int			init_mutex(t_philo *philo, t_table *data);
int			set_philo(t_philo *philo, t_table *data);
int			create_threads(t_philo *philo, t_table *data);
#endif

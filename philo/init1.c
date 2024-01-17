#include "philo.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int set_data(t_philo *philo, t_table *data, int ac, char **av)
{
	int	i;

	i = 0;
	(void)philo;
	while (av[++i])
		if (ft_atoi(av[i]) == -1 || ac < 5 || ac > 6 \
		|| ft_atoi(av[1]) >= 200)
			return (SET_DATA);
	data->eat_count = 0;
	data->start_time = gettime();
	data->lasttime = gettime();
	data->nbr_philos = ft_atoi(av[1]);
	data->time_to_dead = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->fork = (int *)malloc(sizeof(int) * data->nbr_philos);
	if (!data->fork)
		return (SET_DATA);
	memset(data->fork, '\0', data->nbr_philos);
	data->wanted_meals = -1;
	if (av[5])
		data->wanted_meals = 1;
	return (TRUE);
}

int	init_mutex(t_philo *philo, t_table *data)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&data->print, NULL))
		return (INIT_MUTEX);
	if (pthread_mutex_init(&data->is_ate, NULL))
		return (INIT_MUTEX);
	if (pthread_mutex_init(&data->is_die, NULL))
		return (INIT_MUTEX);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
		data->nbr_philos);
	if (!data->forks)
		return (0);
	while (++i < data->nbr_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (INIT_MUTEX);
	}
	return (TRUE);
}

int	set_philo(t_philo *philo, t_table *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		philo->id = i + 1;
	philo->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->nbr_philos);
	if (!philo->philo)
		return (SET_PHILO);
	philo->data = data;
	return (TRUE);
}

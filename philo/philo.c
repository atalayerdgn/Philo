/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:16 by aerdogan          #+#    #+#             */
/*   Updated: 2024/01/18 00:48:10 by aerdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	init_philos(int ac, char **av)
{
	t_philo	*philos;
	t_table	*data;

	philos = (t_philo *)malloc(sizeof(t_philo));
	if (!philos)
		return (FALSE);
	data = (t_table *)malloc(sizeof(t_table));
	if (!data)
		return (FALSE);
	if (set_data(philos, data, ac, av) == SET_DATA)
		return (FALSE);
	if (init_mutex(philos, data) == INIT_MUTEX)
		return (FALSE);
	if (set_philo(philos, data) == SET_PHILO)
		return (FALSE);
	if (create_threads(philos, data) == CREATE_THREAD)
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	if (init_philos(ac, av) == FALSE)
		return (0);
	return (0);
}


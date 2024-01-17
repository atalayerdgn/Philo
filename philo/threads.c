#include "philo.h"

static	void *rout(void *arg)
{
	t_philo *data;

	data = (t_philo *)arg;

	while (1)
	{
		

		if (eat(data) == FALSE)
			return (NULL);
		if (sleep(data) == FALSE)
			return (NULL);
		if (think(data) == FALSE)
			return (NULL);
	}
	return (NULL);
}

int	create_threads(t_philo *philo, t_table *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	(void)data;
	while (i < philo->data->nbr_philos)
	{
		if (pthread_create(&philo->philo[i], NULL, &rout, &philo->data[i]))
			return (CREATE_THREAD);
		i++;
	}
	while (j <= philo->data->nbr_philos)
	{
		pthread_join(philo->philo[j], NULL);
		j++;
	}
	return (TRUE);
}

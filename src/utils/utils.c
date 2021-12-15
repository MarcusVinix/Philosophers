/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:06:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/14 23:43:11 by marcus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long int	get_time(void)
{
	struct timeval	tv;
	long int		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

void	print_status(t_philo *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(&philo->main->print);
	time = get_time() - philo->main->ms_start;
	if (ft_strcmp(action, FORK) == 0)
		printf("%s%ld %i %s%s\n", GRN, time, philo->id, FORK, RESET);
	if (ft_strcmp(action, EAT) == 0)
		printf("%s%ld %i %s%s\n", BLU, time, philo->id, EAT, RESET);
	if (ft_strcmp(action, THINK) == 0)
		printf("%s%ld %i %s%s\n", CYN, time, philo->id, THINK, RESET);
	if (ft_strcmp(action, SLEEP) == 0)
		printf("%s%ld %i %s%s\n", MAG, time, philo->id, SLEEP, RESET);
	if (ft_strcmp(action, DIE) == 0)
		printf("%s%ld %i %s%s\n", RED, time, philo->id, DIE, RESET);
	pthread_mutex_unlock(&philo->main->print);
}

int	free_all(t_main *main, int i)
{
	int	j;

	free(main->forks);
	free(main->philos);
	pthread_mutex_destroy(&main->print);
	j = 0;
	while (j < main->n_philos)
	{
		if (i > 0)
			pthread_mutex_destroy(&main->forks[j]);
		if (i > 1)
			pthread_mutex_destroy(&main->philos[j].mutex);
		j++;
	}
	return (0);
}

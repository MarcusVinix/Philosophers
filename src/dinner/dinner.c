/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:03 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/15 22:45:08 by marcus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*kill_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->forks[0]);
	print_status(philo, FORK);
	usleep(philo->main->ms_to_die * 1000);
	pthread_mutex_unlock(&philo->main->forks[0]);
	print_status(philo, DIE);
	return (NULL);
}

void	*actions(void *param)
{
	t_philo		*philo;

	philo = param;
	if (philo->main->n_philos == 1)
		return (kill_one_philo(philo));
	if (!(philo->id % 2))
		usleep(1000);
	while (!must_die(philo))
	{
		if (!eating(philo))
			break ;
		if (must_die(philo) || !sleeping(philo))
			break ;
		print_status(philo, THINK);
	}
	return (NULL);
}

int	prepare_dinner(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->n_philos)
	{
		main->ms_start = get_time();
		if (pthread_create(&main->philos[i].thread,
				NULL, actions, &main->philos[i]))
			return (FALSE);
	}
	return (start_dinner(main));
}

int	start_dinner(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->n_philos)
	{
		if (pthread_join(main->philos[i].thread, NULL))
			return (FALSE);
		if (main->philos[i].time == -1)
		{
			print_status(&main->philos[i], DIE);
			break ;
		}
	}
	return (TRUE);
}

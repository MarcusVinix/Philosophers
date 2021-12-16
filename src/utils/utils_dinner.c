/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:12:43 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/15 22:37:20 by marcus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->forks[philo->rfork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->main->forks[philo->lfork]);
	print_status(philo, FORK);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->main->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->main->forks[philo->lfork]);
}

int	sleeping(t_philo *philo)
{
	long int	time;

	time = get_time();
	print_status(philo, SLEEP);
	while (get_time() - time < philo->main->ms_to_sleep)
	{
		if (must_die(philo))
			return (FALSE);
		usleep(1000);
	}
	return (TRUE);
}

int	must_die(t_philo *philo)
{
	int	i;
	int	limit;

	i = -1;
	limit = 0;
	while (++i < philo->main->n_philos)
	{
		pthread_mutex_lock(&philo->main->philos[i].mutex);
		if (get_time() - philo->main->philos[i].time >= philo->main->ms_to_die)
		{
			pthread_mutex_unlock(&philo->main->philos[i].mutex);
			philo->main->philos[i].time = -1;
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->main->philos[i].mutex);
		if (philo->main->n_to_eat && philo->n_eat >= philo->main->n_to_eat)
			limit++;
		if (limit == philo->main->n_philos)
			return (TRUE);
	}
	return (FALSE);
}

int	eating(t_philo *philo)
{
	forks(philo);
	if (must_die(philo))
		return (FALSE);
	pthread_mutex_lock(&philo->mutex);
	print_status(philo, EAT);
	pthread_mutex_unlock(&philo->mutex);
	philo->time = get_time();
	while (get_time() - philo->time < philo->main->ms_to_eat)
	{
		if (must_die(philo))
		{
			pthread_mutex_unlock(&philo->mutex);
			unlock_forks(philo);
			return (FALSE);
		}
		usleep(1000);
	}
	unlock_forks(philo);
	philo->n_eat++;
	return (TRUE);
}

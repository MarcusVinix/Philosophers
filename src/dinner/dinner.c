/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:03 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/12 10:43:23 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*actions(void *param)
{
	t_philo		*philo;

	philo = param;
	if (!(philo->id % 2))
		usleep(1000);
	while (!must_die(philo))
	{
		if (!eating(philo))
			break ;
		if (must_die(philo))
			break ;
		if (!sleeping(philo))
			break ;
		print_status(philo, THINK);
	}
	return (NULL);
}

int	prepare_dinner(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->n_philos)
	{
		main->ms_start = get_time();
		if (pthread_create(&main->philos[i].thread,
			NULL, actions, &main->philos[i]))
				return (FALSE);
		i++;
	}
	return (TRUE);
}

int	start_dinner(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->n_philos)
	{
		if (pthread_join(main->philos[i].thread, NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

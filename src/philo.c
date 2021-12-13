/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:21:13 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/12 10:43:29 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_philos(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->n_philos)
	{
		main->philos[i].id = i;
		main->philos[i].time = get_time();
		main->philos[i].lfork = i;
		main->philos[i].rfork = i + 1;
		main->philos[i].main = main;
		if (i + 1 == main->n_philos)
			main->philos[i].rfork = 0;
		if (pthread_mutex_init(&main->forks[i], NULL))
			return (FALSE);
		if (pthread_mutex_init(&main->philos[i].mutex, NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	start_structs(t_main *main)
{
	pthread_mutex_init(&main->print, NULL);
	main->forks = malloc(sizeof(pthread_mutex_t) * main->n_philos);
	ft_bzero(main->forks, sizeof(pthread_mutex_t));
	main->philos = malloc(sizeof(t_philo) * main->n_philos);
	ft_bzero(main->philos, sizeof(t_philo));
	if (!init_philos(main))
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char** argv)
{
	t_main	main;

	if (!check_errors(argc, argv))
		return (1);
	ft_bzero(&main, sizeof(t_main));
	if (!parser_args(argv, &main))
		return (2);
	if (!start_structs(&main))
		return (3);
	if (!prepare_dinner(&main))
		return (4);
	if (!start_dinner(&main))
		return (5);
	return (0);
}
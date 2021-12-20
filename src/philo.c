/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:21:13 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/20 19:10:35 by marcus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_philos(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->n_philos)
	{
		main->philos[i].id = i + 1;
		main->philos[i].time = get_time();
		main->philos[i].lfork = i;
		main->philos[i].rfork = i + 1;
		main->philos[i].main = main;
		if (i + 1 == main->n_philos)
			main->philos[i].rfork = 0;
		if (pthread_mutex_init(&main->forks[i], NULL))
			return (free_all(main, 1));
		if (pthread_mutex_init(&main->philos[i].mutex, NULL))
			return (free_all(main, 2));
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
	return (init_philos(main));
}

int	main(int argc, char **argv)
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
	free_all(&main, 0);
	return (0);
}

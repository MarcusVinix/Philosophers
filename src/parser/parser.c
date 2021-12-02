/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:49:52 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/01 21:59:28 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	add_value(t_args *args, int number, int sig)
{
	if (sig == 1)
		args->n_philos = number;
	else if (sig == 2)
		args->ms_to_die = number;
	else if (sig == 3)
		args->ms_to_eat = number;
	else if (sig == 4)
		args->ms_to_sleep = number;
	else
		args->n_to_eat = number;
}

void	parser_args(int argc, char **argv, t_args *args)
{
	int	i;

	i = argc;
	while (i-- < argc)
		add_value(args, (int)ft_atoi(argv[i]), i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:49:52 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/10 21:50:47 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	add_value(t_main *main, int number, int sig)
{
	if (sig == 1)
		main->n_philos = number;
	else if (sig == 2)
		main->ms_to_die = number;
	else if (sig == 3)
		main->ms_to_eat = number;
	else if (sig == 4)
		main->ms_to_sleep = number;
	else
		main->n_to_eat = number;
}

int	is_all_valid_arg(t_main *main)
{
	if (main->n_philos < 1)
		return (FALSE);
	if (main->ms_to_die == 0)
		return (FALSE);
	if (main->n_to_eat < 1)
		return (FALSE);
	return (TRUE);
}

int	parser_args(char **argv, t_main *main)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		printf("IS %i\n", (int)ft_atoi(argv[i]));
		add_value(main, (int)ft_atoi(argv[i]), i);
	}
	if (!is_all_valid_arg(main))
		return (FALSE);
	return (TRUE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:21:13 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/01 22:06:29 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	start_structs(t_args *args)
{
	ft_bzero(args, sizeof(t_args));
}

int	main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	struct timeval tv;
	struct timezone tz;
	t_args	args;

	if (!check_errors(argc, argv))
		return (FALSE);
	start_structs(&args);
	parser_args(argc, argv, &args);
	printf("n_philo %i\n ms_to_die %i\n ms_to_eat %i\n ms_to_sleep %i\n", args.n_philos,
			args.ms_to_die, args.ms_to_eat, args.ms_to_sleep);
	gettimeofday(&tv, &tz);
	printf("tv_sec %li\n", tv.tv_sec);
	printf("tv_usec %li\n", tv.tv_usec);
	printf("tz_minuteswest %i\n", tz.tz_minuteswest);
	printf("tz_dsttime %i\n", tz.tz_dsttime);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:19:26 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/01 22:03:47 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <colors.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define ARGS "Args: ./philo n_of_philo ms_to_die ms_to_eat ms_to_sleep"
# define NO_NEGINT "The args must be unsigned int bigger then 0"
# define ONLY_DIGITS "Only digits is allowed"

typedef struct s_args
{
	int	n_philos;
	int	ms_to_die;
	int ms_to_eat;
	int	ms_to_sleep;
	int n_to_eat;
}				t_args;

//utils
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);

//errors
int		check_errors(int argc, char **argv);

//parser
void	parser_args(int argc, char **argv, t_args *args);



#endif
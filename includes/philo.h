/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:19:26 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/10 22:50:40 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <colors.h>
# include <limits.h>
# include <pthread.h> 

# define TRUE 1
# define FALSE 0
# define ARGS "Args: ./philo n_of_philo ms_to_die ms_to_eat ms_to_sleep"
# define NO_NEGINT "The args must be unsigned int bigger then 0"
# define ONLY_DIGITS "Only digits is allowed"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_philo
{
	int				id;
	long int		time;
	int				lfork;
	int				rfork;
	t_main			*main;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}				t_philo;
typedef struct s_main
{
	int				n_philos;
	int				ms_to_die;
	int				ms_to_eat;
	int				ms_to_sleep;
	int				n_to_eat;
	long int		ms_start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_main;

//utils
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
long int	get_time();
void		print_status(t_philo *philo, char *action);


//errors
int			check_errors(int argc, char **argv);

//parser
int			parser_args(char **argv, t_main *main);



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:06:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/10 22:50:02 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (TRUE);
	else
		return (FALSE);
}

int	ft_atoi(const char *nptr)
{
	long	number;

	number = 0;
	while (ft_isdigit(*nptr))
		number = number * 10 + (*nptr++ - '0');
	return (number);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_s;
	size_t			i;

	i = 0;
	s_s = (unsigned char *)s;
	while (i < n)
	{
		s_s[i] = '\0';
		i++;
	}
}

long int	get_time()
{
	struct timeval tv;
	long int milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	while (s_s1[i] || s_s2[i])
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		i++;
	}	
	return (0);
}

void	print_status(t_philo *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(&philo->main->print);
	time = get_time() - philo->main->ms_start;
	if (ft_strcmp(action, FORK) == 0)
		printf("%s%ld %i %s%s\n", GRN, time, philo->id, FORK, RESET);
	if (ft_strcmp(action, EAT) == 0)
		printf("%s%ld %i %s%s\n", BLUE, time, philo->id, EAT, RESET);
	if (ft_strcmp(action, THINK) == 0)
		printf("%s%ld %i %s%s\n", CYN, time, philo->id, THINK, RESET);
	if (ft_strcmp(action, SLEEP) == 0)
		printf("%s%ld %i %s%s\n", MAG, time, philo->id, SLEEP, RESET);
	if (ft_strcmp(action, DIE) == 0)
		printf("%s%ld %i %s%s\n", RED, time, philo->id, DIE, RESET);
	pthread_mutex_unlock(&philo->main->print);
}
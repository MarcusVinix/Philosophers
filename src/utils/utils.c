/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:06:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/01 22:00:44 by mavinici         ###   ########.fr       */
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
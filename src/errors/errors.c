/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:26:21 by mavinici          #+#    #+#             */
/*   Updated: 2021/12/10 19:33:16 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	valid_number(int number)
{
	if (number > INT_MAX || number == 0)
		return (FALSE);
	else
		return (TRUE);
}

int	is_all_valid_numbers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_atoi(argv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	print_error_arg(char *message)
{
	printf("%s%s%s\n", YEL, message, RESET);
	return (FALSE);
}

int	check_errors(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_error_arg(ARGS));
	if (!is_all_digits(argv))
		return (print_error_arg(ONLY_DIGITS));
	if (!is_all_valid_numbers(argv))
		return (print_error_arg(NO_NEGINT));
	return (TRUE);
}
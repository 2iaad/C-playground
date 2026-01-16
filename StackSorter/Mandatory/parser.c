/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:40:36 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/13 17:22:12 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	white_spaces_checker(char *av)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (av[j])
	{
		if (av[j] >= '0' && av[j] <= '9')
			k = 1337;
		j++;
	}
	if (k != 1337)
		return (false);
	return (true);
}

bool	arg_checker_if_sorted(char **s_s)
{
	int	i;

	i = 0;
	while (s_s[i] && s_s[i + 1])
	{
		if (ft_atol(s_s[i]) > ft_atol(s_s[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

bool	arg_checker_pure_numbers(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		i = 0;
		if (((s[j])[i] == '+' || (s[j])[i] == '-') && s[j][1])
			i++;
		while ((s[j])[i])
		{
			if (!(s[j][i] >= '0' && s[j][i] <= '9'))
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	arg_checker_repeated_numbers(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[i] && s[j])
		{
			if (ft_atol(s[i]) == ft_atol(s[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	arg_checker_if_integers(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

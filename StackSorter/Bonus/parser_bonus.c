/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:40:36 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/12 17:00:46 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

bool	arg_checker_if_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	arg_checker_pure_numbers(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (!s[j][0])
			exit(0);
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

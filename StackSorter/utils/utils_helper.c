/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:20:00 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:43:39 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !stack)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);
	while (*stack)
		ft_lstclear(stack);
}

long	ft_atol(const char *str)
{
	int		i;
	int		s;
	long	nb;

	i = 0;
	s = 1;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * s > INT_MAX)
			return (LONG_MAX);
		else if (nb * s < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	return (nb * s);
}

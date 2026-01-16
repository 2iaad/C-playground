/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:58:44 by zderfouf          #+#    #+#             */
/*   Updated: 2023/11/27 16:14:34 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long long	nb;
	long long	tempo;

	i = 0;
	s = 1;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		s = check_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tempo = nb * 10 + (str[i] - '0');
		if (tempo < nb && s == 1)
			return (-1);
		if (tempo < nb && s == -1)
			return (0);
		nb = tempo;
		i++;
	}
	return (nb * s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:43:51 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/24 17:04:51 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_commas(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	return (c);
}

void	small_parser(char **tmp, t_data **data, int *c)
{
	if (!ft_strcmp(tmp[0], "F"))
	{
		if (count_commas(tmp[1]) != 2)
			return (write(2, "Error\nInvalide colors.\n", 23), exit(1));
		(1) && ((*data)->colors[0][1] = ft_strdup(tmp[1])), (*c)++;
	}
	else if (!ft_strcmp(tmp[0], "C"))
	{
		if (count_commas(tmp[1]) != 2)
			return (write(2, "Error\nInvalide colors.\n", 23), exit(1));
		(1) && ((*data)->colors[1][1] = ft_strdup(tmp[1])), (*c)++;
	}
}

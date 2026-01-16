/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:13:48 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/24 16:11:43 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	skip_spaces(int *i, char **file)
{
	while (file[*i] && file[*i][0] == '\n')
		(*i)++;
}

void	init_rgb(t_data **data)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split((*data)->colors[0][1], ',');
	while (i < 3)
	{
		(*data)->f_rgb[i] = ft_atol(tmp[i]);
		if ((*data)->f_rgb[i] == -1)
			return (write(2, "Error\nInvalide colors.\n", 23), exit(1));
		i++;
	}
	ft_free(tmp);
	i = 0;
	tmp = ft_split((*data)->colors[1][1], ',');
	while (i < 3)
	{
		(*data)->c_rgb[i] = ft_atol(tmp[i]);
		if ((*data)->c_rgb[i] == -1)
			return (write(2, "Error\nInvalide colors.\n", 23), exit(1));
		i++;
	}
	ft_free(tmp);
}

bool	pure_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '\n')
			return (false);
		while (str[i][j] && str[i][j] != '\n')
		{
			if (j == 0 && (str[i][0] == '-' || str[i][0] == '+'))
				j++;
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	parse_colors(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->colors[i])
	{
		tmp = ft_split(data->colors[i][1], ',');
		if (ptr_counter(tmp) != 3 || !pure_numbers(tmp))
		{
			write(2, "Error\nInvalide colors.\n", 23);
			exit(1);
		}
		ft_free(tmp);
		i++;
	}
	init_rgb(&data);
}

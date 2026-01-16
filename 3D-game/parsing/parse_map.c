/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:45:59 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/25 15:40:35 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	valid_characters(char **s)
{
	int			i;
	int			j;
	int			k;

	(1) && (i = -1), (k = 0);
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] != 'N' &&
					s[i][j] != 'S' && s[i][j] != 'E' && s[i][j] != 'W'
					&& s[i][j] != '\n' && s[i][j] != ' ')
				return (false);
			if (s[i][j] == 'N' || s[i][j] == 'S' || s[i][j] == 'E'
					|| s[i][j] == 'W')
				k++;
		}
	}
	if (k != 1)
		return (false);
	return (true);
}

bool	walls_check(char **map)
{
	int	i;
	int	j;

	(1) && (i = -1), (j = 0);
	while (map[j])
		j++;
	while (map[0][++i])
		if (map[0][i] != '1' && map[0][i] != ' ' && map[0][i] != '\n')
			return (false);
	i = -1;
	while (map[j - 1][++i])
		if (map[j - 1][i] != '1' && map[j - 1][i] != 32 && map[j - 1][i] != 10)
			return (false);
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (false);
	i = -1;
	while (map[++i] && i < (j - 1))
		if (map[i][ft_strlen(map[i]) - 1] != '\n')
			return (false);
	if (map[i][ft_strlen(map[i]) - 1] != '1'
		&& map[i][ft_strlen(map[i]) - 1] != '\n')
		return (false);
	return (true);
}

bool	zeros_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (zero_helper(map[i][j + 1]) || zero_helper(map[i][j - 1])
					|| zero_helper(map[i + 1][j]) || zero_helper(map[i - 1][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	player_env(t_data *data)
{
	if (data->squared_map[data->ply_y][data->ply_x - 1] == ' '
		|| data->squared_map[data->ply_y][data->ply_x + 1] == ' '
		|| data->squared_map[data->ply_y - 1][data->ply_x] == ' '
		|| data->squared_map[data->ply_y + 1][data->ply_x] == ' ')
		return (false);
	return (true);
}

void	parse_map(t_data *data)
{
	if (!valid_characters(data->map2d) || !walls_check(data->map2d)
		|| !zeros_walls(data->squared_map) || !player_env(data))
	{
		write(2, "Error\nInvalide map.\n", 20);
		exit(1);
	}
}

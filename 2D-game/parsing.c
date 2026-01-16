/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:44:05 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/30 21:27:08 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(char **map)
{
	if (!valid_characters(map) || !rectangular_check(map) || !walls_check(map))
	{
		write(2, "Error\nInvalide map.", 20);
		exit(1);
	}
}

bool	valid_characters(char **s)
{
	int			i;
	int			j;
	static int	k[3] = {0};

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] != 'C' &&
					s[i][j] != 'E' && s[i][j] != 'P' && s[i][j] != '\n')
				return (false);
			if (s[i][j] == 'E')
				k[0]++;
			if (s[i][j] == 'P')
				k[1]++;
			if (s[i][j] == 'C')
				k[2]++;
		}
	}
	if (k[0] != 1 || k[1] != 1 || k[2] < 1)
		return (false);
	return (true);
}

bool	rectangular_check(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	if (ft_strlen(s[0]) != (ft_strlen(s[j - 1]) + 1))
		return (false);
	while (s[i] && i < (j - 1))
	{
		if (ft_strlen(s[0]) != ft_strlen(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	walls_check(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (s[0][j] != '\n')
	{
		if (s[0][j] != '1' || s[i - 1][j] != '1')
			return (false);
		j++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1' || s[i][ft_strlen(s[i]) - 2] != '1')
			return (false);
		i++;
	}
	return (true);
}

char	**map_copy(char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = (char **) malloc (sizeof(char *) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = ft_strdup(str[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

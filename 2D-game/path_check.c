/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:00:30 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/31 00:35:25 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char **str)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'C')
				c++;
		}
	}
	return (c);
}

void	look_for_p(char **str, int *i, int *j)
{
	int	sign;
	int	a;
	int	b;

	a = -1;
	sign = 0;
	while (sign != 1337 && str[++a])
	{
		b = -1;
		while (str[a][++b])
		{
			if (str[a][b] == 'P')
			{
				sign = 1337;
				break ;
			}
		}
	}
	*i = a;
	*j = b;
}

int	flood_fill(char **tmp, int i, int j, int coins_count)
{
	static int	c;
	static int	e;

	if (tmp[i][j] == 'E')
	{
		e = 1337;
		tmp[i][j] = '1';
		return (1);
	}
	if (tmp[i][j] == 'C')
		c++;
	tmp[i][j] = '1';
	if (tmp[i][j + 1] != '1')
		flood_fill(tmp, i, j + 1, coins_count);
	if (tmp[i][j - 1] != '1')
		flood_fill(tmp, i, j - 1, coins_count);
	if (tmp[i - 1][j] != '1')
		flood_fill(tmp, i - 1, j, coins_count);
	if (tmp[i + 1][j] != '1')
		flood_fill(tmp, i + 1, j, coins_count);
	if (c == coins_count && e == 1337)
		return (0);
	return (1);
}

void	path_check(char **str)
{
	int		i;
	int		j;
	int		coins_count;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = map_copy(str);
	coins_count = count_coins(tmp);
	look_for_p(tmp, &i, &j);
	if (flood_fill(tmp, i, j, coins_count))
	{
		write(2, "Error\nInvalide path.", 20);
		return (ft_free(str), ft_free(tmp), exit(1));
	}
	ft_free(tmp);
}

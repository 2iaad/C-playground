/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:33:48 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/24 16:17:35 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	ft_free(data->map2d);
	ft_free(data->squared_map);
	ft_lstclear(&data->tex_info);
	while (data->textures[i])
	{
		ft_free(data->textures[i]);
		i++;
	}
	i = 0;
	while (data->colors[i])
	{
		ft_free(data->colors[i]);
		i++;
	}
	free(data);
}

char	*strcpy_with_spaces(char *src, int len)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *) malloc (sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = ' ';
		i++;
	}
	dst[len - 1] = '\n';
	dst[len] = '\0';
	return (dst);
}

bool	zero_helper(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (true);
	return (false);
}

int	ptr_counter(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int	ft_atol(char *s)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		if (nb > 255)
			return (-1);
		i++;
	}
	if (sign * nb < 0)
		return (-1);
	return (sign * nb);
}

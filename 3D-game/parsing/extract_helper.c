/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:19:44 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/22 23:19:00 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_t_struct(t_data **data)
{
	int	i;

	i = 0;
	(*data)->tex_info = NULL;
	while ((*data)->textures[i])
	{
		ft_lstadd_back(&(*data)->tex_info, ft_lstnew((*data)->textures[i][0],
				(*data)->textures[i][1]));
		i++;
	}
}

void	extract_ppos(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*data)->map2d[i])
	{
		j = 0;
		while ((*data)->map2d[i][j])
		{
			if ((*data)->map2d[i][j] == 'N' || (*data)->map2d[i][j] == 'S'
				|| (*data)->map2d[i][j] == 'E' || (*data)->map2d[i][j] == 'W')
			{
				return ((void)((*data)->ply_x = j, (*data)->ply_y = i));
			}
			j++;
		}
		i++;
	}
}

void	extract_map(char **file, t_data **data)
{
	int	i;
	int	j;
	int	start;
	int	end;

	(1) && (i = 0, j = 0);
	while (file[i])
		i++;
	end = i;
	while (file[--i])
	{
		if (file[i][0] == '\n')
			break ;
	}
	start = i + 1;
	(*data)->offset = start;
	(*data)->map2d = (char **)malloc(sizeof(char *) * end - start + 1);
	while (file[++i])
	{
		(*data)->map2d[j] = ft_strdup(file[i]);
		j++;
	}
	(*data)->map2d[j] = NULL;
}

void	extract_squared_map(t_data **data)
{
	int	i;

	(1) && ((*data)->w_map = 0), ((*data)->h_map = 0), (i = 0);
	while ((*data)->map2d[(*data)->h_map])
		(*data)->h_map++;
	while ((*data)->map2d[i])
	{
		if (ft_strlen((*data)->map2d[i]) > (*data)->w_map)
			(*data)->w_map = ft_strlen((*data)->map2d[i]);
		i++;
	}
	(*data)->squared_map = (char **)malloc(sizeof(char *)
			* ((*data)->h_map + 1));
	i = 0;
	while ((*data)->map2d[i])
	{
		(*data)->squared_map[i] = strcpy_with_spaces((*data)->map2d[i],
				(*data)->w_map);
		i++;
	}
	(*data)->squared_map[i] = NULL;
}

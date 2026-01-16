/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:30:59 by ibouram           #+#    #+#             */
/*   Updated: 2024/12/22 06:04:31 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rev_b(int c)
{
	unsigned int	byte;

	byte = 0;
	byte |= (c & 0xFF) << 24;
	byte |= (c & 0xFF00) << 8;
	byte |= (c & 0xFF0000) >> 8;
	byte |= (c & 0xFF000000) >> 24;
	return (byte);
}

int	get_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	valid_texture(t_texture_info *tex_info)
{
	if (ft_strcmp(tex_info->id, "NO") && ft_strcmp(tex_info->id, "SO")
		&& ft_strcmp(tex_info->id, "WE") && ft_strcmp(tex_info->id, "EA"))
		return (0);
	return (1);
}

int	validate_texture(t_texture_info *info)
{
	t_texture_info	*current;
	mlx_texture_t	*texture;

	current = info;
	while (current)
	{
		if (valid_texture(current))
		{
			if (current->path
				&& current->path[ft_strlen(current->path) - 1] == '\n')
				current->path[ft_strlen(current->path) - 1] = '\0';
			texture = mlx_load_png(current->path);
			if (texture == NULL)
				return (0);
			mlx_delete_texture(texture);
		}
		current = current->next;
	}
	return (1);
}

int	textures(t_texture_info *info, t_textures *textures)
{
	t_texture_info	*current;

	current = info;
	if (!validate_texture(info))
		return (0);
	while (current)
	{
		if (!ft_strcmp(current->id, "NO"))
			textures->north = mlx_load_png(current->path);
		else if (!ft_strcmp(current->id, "WE"))
			textures->west = mlx_load_png(current->path);
		else if (!ft_strcmp(current->id, "SO"))
			textures->south = mlx_load_png(current->path);
		else if (!ft_strcmp(current->id, "EA"))
			textures->east = mlx_load_png(current->path);
		current = current->next;
	}
	return (1);
}

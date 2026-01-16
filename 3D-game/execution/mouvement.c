/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:33:02 by ibouram           #+#    #+#             */
/*   Updated: 2024/12/22 05:55:40 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_delet_texture(t_textures *textures)
{
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->west)
		mlx_delete_texture(textures->west);
	if (textures->east)
		mlx_delete_texture(textures->east);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	move(t_mlx *mx, int ang)
{
	double	y;
	double	x;
	int		i;
	int		j;

	x = mx->ply->player_x + 5.0 * cos(mx->ply->ply_angle + (ang * M_PI / 180));
	y = mx->ply->player_y + 5.0 * sin(mx->ply->ply_angle + (ang * M_PI / 180));
	i = (int)(y / TILE_SIZE);
	j = (int)(x / TILE_SIZE);
	if (mx->dt->map2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] != '1'
			&& mx->dt->map2d[(int)(mx->ply->player_y / TILE_SIZE)][j] != '1'
		&& mx->dt->map2d[i][(int)(mx->ply->player_x / TILE_SIZE)] != '1')
	{
		mx->ply->player_x = x;
		mx->ply->player_y = y;
	}
}

void	rotate(t_mlx *mlx, double angle)
{
	mlx->ply->ply_angle += angle * M_PI / 180;
	if (mlx->ply->ply_angle > 2 * M_PI)
		mlx->ply->ply_angle -= 2 * M_PI;
	if (mlx->ply->ply_angle < 0)
		mlx->ply->ply_angle += 2 * M_PI;
}

void	keys_hook(void	*hook)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)hook;
	if (mlx_is_key_down(mlx->mlx_p, 256))
		mlx_close_window(mlx->mlx_p);
	if (mlx_is_key_down(mlx->mlx_p, 262))
		rotate(mlx, 3.0);
	if (mlx_is_key_down(mlx->mlx_p, 263))
		rotate(mlx, -3.0);
	if (mlx_is_key_down(mlx->mlx_p, 87))
		move(mlx, 0);
	if (mlx_is_key_down(mlx->mlx_p, 83))
		move(mlx, 180);
	if (mlx_is_key_down(mlx->mlx_p, 65))
		move(mlx, 270);
	if (mlx_is_key_down(mlx->mlx_p, 68))
		move(mlx, 90);
}

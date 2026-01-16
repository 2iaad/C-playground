/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:30:21 by ibouram           #+#    #+#             */
/*   Updated: 2024/12/21 20:34:04 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	hit_the_wall(t_mlx *mlx, float x, float y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (1);
	x_m = (int)(x / TILE_SIZE);
	y_m = (int)(y / TILE_SIZE);
	if (y_m >= mlx->dt->h_map || x_m >= mlx->dt->w_map)
		return (1);
	if (mlx->dt->map2d[y_m] && x_m <= (int)ft_strlen(mlx->dt->map2d[y_m]))
		if (mlx->dt->map2d[y_m][x_m] == '1')
			return (1);
	return (0);
}

void	find_distance(float h_inter, float v_inter, t_mlx *mlx)
{
	if (v_inter < h_inter)
	{
		mlx->distance = v_inter;
		mlx->flg = 0;
	}
	else
	{
		mlx->distance = h_inter;
		mlx->flg = 1;
	}
}

float	horizontal_distance(t_mlx *mlx)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		checker;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(mlx->ray_angle);
	h_y = floor(mlx->ply->player_y / TILE_SIZE) * TILE_SIZE;
	if (mlx->ray_angle > 0 && mlx->ray_angle < M_PI)
		(1) && (h_y += TILE_SIZE, checker = -1);
	else
		(1) && (y_step *= -1, checker = 1);
	h_x = mlx->ply->player_x + (h_y - mlx->ply->player_y) / tan(mlx->ray_angle);
	if ((x_step > 0 && (mlx->ray_angle > (M_PI / 2)
				&& mlx->ray_angle < (3 * M_PI) / 2))
		|| (x_step < 0 && (!(mlx->ray_angle > (M_PI / 2)
					&& mlx->ray_angle < (3 * M_PI) / 2))))
		x_step *= -1;
	while (!hit_the_wall(mlx, h_x, h_y - checker))
		(1) && (h_y += y_step, h_x += x_step);
	mlx->x_h = h_x;
	mlx->y_h = h_y;
	return (sqrt(pow(h_y - mlx->ply->player_y, 2)
			+ pow(h_x - mlx->ply->player_x, 2)));
}

float	vertical_distance(t_mlx *mlx)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		checker;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(mlx->ray_angle);
	v_x = floor(mlx->ply->player_x / TILE_SIZE) * TILE_SIZE;
	if (!(mlx->ray_angle > M_PI / 2 && mlx->ray_angle < 3 * M_PI / 2))
		(1) && (v_x += TILE_SIZE, checker = -1);
	else
		(1) && (x_step *= -1, checker = 1);
	v_y = mlx->ply->player_y + (v_x - mlx->ply->player_x) * tan(mlx->ray_angle);
	if ((y_step < 0 && (mlx->ray_angle > 0 && mlx->ray_angle < M_PI))
		|| (y_step > 0 && (!(mlx->ray_angle > 0 && mlx->ray_angle < M_PI))))
		y_step *= -1;
	while (!hit_the_wall(mlx, v_x - checker, v_y))
		(1) && (v_y += y_step, v_x += x_step);
	mlx->x_v = v_x;
	mlx->y_v = v_y;
	return (sqrt(pow(v_y - mlx->ply->player_y, 2)
			+ pow(v_x - mlx->ply->player_x, 2)));
}

void	ray_casting(t_mlx *mlx)
{
	double	h;
	double	v;
	double	step;
	int		i;

	i = 0;
	step = mlx->ply->fov_rd / WIDTH;
	mlx->ray_angle = mlx->ply->ply_angle - (mlx->ply->fov_rd / 2);
	while (i < WIDTH)
	{
		mlx->ray_angle = nor_angle(mlx->ray_angle);
		h = horizontal_distance(mlx);
		v = vertical_distance(mlx);
		find_distance(h, v, mlx);
		render(mlx, i);
		i++;
		mlx->ray_angle += step;
	}
}

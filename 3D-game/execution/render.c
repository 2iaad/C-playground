/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:31:45 by ibouram           #+#    #+#             */
/*   Updated: 2024/12/22 06:01:11 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_texture_t	*wall_check(t_mlx *mlx)
{
	mlx->ray_angle = nor_angle(mlx->ray_angle);
	if (mlx->flg == 1)
	{
		if (mlx->ray_angle > 0 && mlx->ray_angle < M_PI)
			return (mlx->textures->south);
		else
			return (mlx->textures->north);
	}
	else
	{
		if (mlx->ray_angle > M_PI / 2 && mlx->ray_angle < 3 * (M_PI / 2))
			return (mlx->textures->east);
		else
			return (mlx->textures->west);
	}
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (y < 0)
		return ;
	else if (y >= HEIGHT)
		return ;
	if (x < 0)
		return ;
	else if (x >= WIDTH)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

void	rend_floor(t_mlx *mlx, int ray, int top, int but)
{
	int		i;
	int		floor_color;
	int		ceiling_color;

	floor_color = get_rgba(mlx->dt->f_rgb[0],
			mlx->dt->f_rgb[1], mlx->dt->f_rgb[2], 255);
	i = but;
	while (i < HEIGHT)
	{
		put_pixel(mlx, ray, i, floor_color);
		i++;
	}
	ceiling_color = get_rgba(mlx->dt->c_rgb[0],
			mlx->dt->c_rgb[1], mlx->dt->c_rgb[2], 255);
	i = 0;
	while (i < top)
	{
		put_pixel(mlx, ray, i, ceiling_color);
		i++;
	}
}

void	wall(t_mlx *mlx, double wall_h, int top, int but)
{
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			x_offset;
	double			y_offset;
	double			fact;

	texture = wall_check(mlx);
	arr = (uint32_t *)texture->pixels;
	if (mlx->flg == 0)
		x_offset = (int)fmodf(mlx->y_v * (texture->width / TILE_SIZE),
				texture->width);
	else
		x_offset = (int)fmodf(mlx->x_h * (texture->width / TILE_SIZE),
				texture->width);
	fact = (double)texture->height / wall_h;
	y_offset = (top - (HEIGHT / 2) + (wall_h / 2)) * fact;
	if (y_offset < 0)
		y_offset = 0;
	while (top < but)
	{
		put_pixel(mlx, mlx->ray, top, rev_b(arr[(int)y_offset * texture->width
				+ (int)x_offset]));
		y_offset += fact;
		top++;
	}
}

void	render(t_mlx *mlx, int ray)
{
	double	w_h;
	double	buttom;
	double	top;

	mlx->distance *= cos(nor_angle(mlx->ray_angle - mlx->ply->ply_angle));
	w_h = (TILE_SIZE / mlx->distance)
		* ((WIDTH / 2) / tan(mlx->ply->fov_rd / 2));
	buttom = (HEIGHT / 2) + (w_h / 2);
	top = (HEIGHT / 2) - (w_h / 2);
	if (top < 0)
		top = 0;
	if (buttom > HEIGHT)
		buttom = HEIGHT;
	mlx->ray = ray;
	wall(mlx, w_h, top, buttom);
	rend_floor(mlx, ray, top, buttom);
}

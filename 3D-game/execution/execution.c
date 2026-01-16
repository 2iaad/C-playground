/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:01:31 by ibouram           #+#    #+#             */
/*   Updated: 2024/12/25 15:36:17 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clean(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	free_data(mlx->dt);
	ft_delet_texture(mlx->textures);
	free(mlx->ply);
	mlx_terminate(mlx->mlx_p);
	exit(0);
}

void	draw(void *m)
{
	t_mlx	*mlx;

	mlx = m;
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, WIDTH, HEIGHT);
	keys_hook(mlx);
	ray_casting(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

void	init_play(t_mlx *mlx)
{
	int	p_x;
	int	p_y;

	p_x = mlx->dt->ply_x;
	p_y = mlx->dt->ply_y;
	if (mlx->dt->map2d[p_y][p_x] == 'N')
		mlx->ply->ply_angle = 3 * M_PI / 2;
	else if (mlx->dt->map2d[p_y][p_x] == 'S')
		mlx->ply->ply_angle = M_PI / 2;
	else if (mlx->dt->map2d[p_y][p_x] == 'E')
		mlx->ply->ply_angle = 0;
	else if (mlx->dt->map2d[p_y][p_x] == 'W')
		mlx->ply->ply_angle = M_PI;
	mlx->ply->player_x = (p_x * TILE_SIZE) + TILE_SIZE / 2;
	mlx->ply->player_y = (p_y * TILE_SIZE) + TILE_SIZE / 2;
	mlx->ply->fov_rd = FOV * M_PI / 180;
}

void	init(t_data *data)
{
	t_mlx	mlx;

	mlx.dt = data;
	mlx.ply = malloc(sizeof(t_player));
	if (!mlx.ply)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	mlx.mlx_p = mlx_init(WIDTH, HEIGHT, "Cub3D", 0);
	if (!mlx.mlx_p)
	{
		ft_clean(&mlx);
		return ;
	}
	if (!textures(data->tex_info, mlx.textures))
	{
		ft_clean(&mlx);
		return ;
	}
	init_play(&mlx);
	mlx_loop_hook(mlx.mlx_p, &draw, &mlx);
	mlx_loop(mlx.mlx_p);
	ft_clean(&mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || special_strcmp(av[1], ".cub"))
		return (0);
	init_data(av[1], &data);
	parsing(data);
	init(data);
	return (free_data(data), 0);
}

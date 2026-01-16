/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:29 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/31 00:37:47 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit(EXIT_SUCCESS);
	return (0);
}

void	calculate_window_size(int *x, int *y, char **str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[b][a])
		a++;
	while (str[b])
		b++;
	if (a > 52 || b > 28)
		return (ft_free(str), exit(1));
	*x = a - 1;
	*y = b;
}

int	event_listener(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 53)
		return (ft_free(mlx->map), exit(0), 1);
	look_for_p(mlx->map, &mlx->i, &mlx->j);
	if (keycode == 124)
		right(mlx);
	if (keycode == 123)
		left(mlx);
	if (keycode == 126)
		up(mlx);
	if (keycode == 125)
		down(mlx);
	return (0);
}

void	mlx(char **str)
{
	t_mlx	mlx;
	int		k;

	k = 1;
	mlx.map = str;
	mlx.moves = 0;
	mlx.coins = count_coins(mlx.map);
	mlx.w = mlx_xpm_file_to_image(mlx.ptr, "images/walls.xpm", &k, &k);
	mlx.f = mlx_xpm_file_to_image(mlx.ptr, "images/floor.xpm", &k, &k);
	mlx.p = mlx_xpm_file_to_image(mlx.ptr, "images/gost.xpm", &k, &k);
	mlx.d = mlx_xpm_file_to_image(mlx.ptr, "images/door.xpm", &k, &k);
	mlx.c = mlx_xpm_file_to_image(mlx.ptr, "images/c.xpm", &k, &k);
	if (!mlx.w || !mlx.f || !mlx.p || !mlx.d || !mlx.c)
		return (ft_free(mlx.map), exit(1));
	calculate_window_size(&mlx.x, &mlx.y, str);
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (ft_free(mlx.map), exit(1));
	mlx.win = mlx_new_window(mlx.ptr, mlx.x * 50, mlx.y * 50, "so_long");
	if (!mlx.win)
		return (free(mlx.ptr), ft_free(mlx.map), exit(1));
	mlx_loop_hook(mlx.ptr, &render_assets, &mlx);
	mlx_hook(mlx.win, 2, 0, event_listener, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.ptr);
}

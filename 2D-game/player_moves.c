/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:56:34 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/29 11:37:42 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j + 1] == '1')
		return ;
	if (mlx->map[mlx->i][mlx->j + 1] == 'E' && mlx->coins == 0)
		exit(0);
	if (mlx->map[mlx->i][mlx->j + 1] == 'E' && mlx->coins != 0)
		return ;
	if (mlx->map[mlx->i][mlx->j + 1] == 'C')
		mlx->coins--;
	mlx->map[mlx->i][mlx->j + 1] = 'P';
	mlx->map[mlx->i][mlx->j] = '0';
	ft_putnbr(++mlx->moves);
	write(1, "\n", 1);
}

void	left(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j - 1] == '1')
		return ;
	if (mlx->map[mlx->i][mlx->j - 1] == 'E' && mlx->coins == 0)
		exit(0);
	if (mlx->map[mlx->i][mlx->j - 1] == 'E' && mlx->coins != 0)
		return ;
	if (mlx->map[mlx->i][mlx->j - 1] == 'C')
		mlx->coins--;
	mlx->map[mlx->i][mlx->j - 1] = 'P';
	mlx->map[mlx->i][mlx->j] = '0';
	ft_putnbr(++mlx->moves);
	write(1, "\n", 1);
}

void	up(t_mlx *mlx)
{
	if (mlx->map[mlx->i - 1][mlx->j] == '1')
		return ;
	if (mlx->map[mlx->i - 1][mlx->j] == 'E' && mlx->coins == 0)
		exit(0);
	if (mlx->map[mlx->i - 1][mlx->j] == 'E' && mlx->coins != 0)
		return ;
	if (mlx->map[mlx->i - 1][mlx->j] == 'C')
		mlx->coins--;
	mlx->map[mlx->i - 1][mlx->j] = 'P';
	mlx->map[mlx->i][mlx->j] = '0';
	ft_putnbr(++mlx->moves);
	write(1, "\n", 1);
}

void	down(t_mlx *mlx)
{
	if (mlx->map[mlx->i + 1][mlx->j] == '1')
		return ;
	if (mlx->map[mlx->i + 1][mlx->j] == 'E' && mlx->coins == 0)
		exit(0);
	if (mlx->map[mlx->i + 1][mlx->j] == 'E' && mlx->coins != 0)
		return ;
	if (mlx->map[mlx->i + 1][mlx->j] == 'C')
		mlx->coins--;
	mlx->map[mlx->i + 1][mlx->j] = 'P';
	mlx->map[mlx->i][mlx->j] = '0';
	ft_putnbr(++mlx->moves);
	write(1, "\n", 1);
}

int	render_assets(t_mlx *mlx)
{
	mlx->a = -1;
	while (mlx->map[++mlx->a])
	{
		mlx->b = -1;
		while (mlx->map[mlx->a][++mlx->b])
		{
			if (mlx->map[mlx->a][mlx->b] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->w,
					mlx->b * 50, mlx->a * 50);
			else
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->f,
					mlx->b * 50, mlx->a * 50);
			if (mlx->map[mlx->a][mlx->b] == 'P')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->p,
					mlx->b * 50, mlx->a * 50);
			if (mlx->map[mlx->a][mlx->b] == 'C')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->c,
					mlx->b * 50, mlx->a * 50);
			if (mlx->map[mlx->a][mlx->b] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->d,
					mlx->b * 50, mlx->a * 50);
		}
	}
	return (0);
}

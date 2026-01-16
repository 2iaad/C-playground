/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:30:59 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/30 21:47:56 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "/usr/local/include/mlx.h"
# include <stdbool.h>

typedef struct s_mlx
{
	int		a;
	int		b;
	int		i;
	int		j;
	int		x;
	int		y;
	int		coins;
	int		moves;
	char	**map;
	void	*ptr;
	void	*win;
	void	*w;
	void	*f;
	void	*p;
	void	*c;
	void	*d;
}	t_mlx;

void	ft_free(char **str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	ft_putnbr(int nb);

void	parsing(char **map);
bool	valid_characters(char **s);
bool	rectangular_check(char **s);
bool	walls_check(char **s);
char	**map_copy(char **str);

int		count_coins(char **str);
void	look_for_p(char **str, int *i, int *j);
void	path_check(char **str);

void	mlx(char **str);
int		render_assets(t_mlx *mlx);

void	right(t_mlx *mlx);
void	left(t_mlx *mlx);
void	up(t_mlx *mlx);
void	down(t_mlx *mlx);

#endif

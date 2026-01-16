/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:22:06 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/24 17:04:43 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../.MLX/MLX42.h"

# define WIDTH 1800
# define HEIGHT 900
# define TILE_SIZE 32
# define FOV 60

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
}	t_textures;

typedef struct s_texture_info
{
	char					*id;
	char					*path;
	struct s_texture_info	*next;
}	t_texture_info;

typedef struct s_player
{
	double	player_x;
	double	player_y;
	float	fov_rd;
	double	ply_angle;
}	t_player;

typedef struct s_data
{
	char			**map2d;
	int				ply_x;
	int				ply_y;
	int				w_map;
	int				h_map;
	bool			error;
	int				offset;
	char			**squared_map;
	char			**textures[5];
	char			**colors[3];
	int				c_rgb[4];
	int				f_rgb[4];
	t_texture_info	*tex_info;
}	t_data;

typedef struct s_mlx
{
	mlx_t			*mlx_p;
	double			ray_angle;
	double			distance;
	double			x_h;
	double			y_h;
	double			x_v;
	double			y_v;
	int				ray;
	int				flg;
	mlx_image_t		*img;
	t_player		*ply;
	t_textures		*textures;
	t_texture_info	*tex_info;
	t_data			*dt;
}	t_mlx;

float			nor_angle(float angle);
void			ray_casting(t_mlx *mlx);
void			keys_hook(void	*hook);
void			render(t_mlx *mlx, int ray);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
int				get_rgba(int r, int g, int b, int a);
int				rev_b(int c);
int				textures(t_texture_info *info, t_textures *textures);
void			ft_delet_texture(t_textures *textures);
void			ft_free(char **str);
int				ft_strlen(char *str);
int				ptr_counter(char **ptr);
int				ft_strcmp(char *s1, char *s2);
int				special_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src);
char			**ft_split(const char *s, char c);
int				ft_atol(char *s);
int				count_commas(char *str);
void			small_parser(char **tmp, t_data **data, int *c);
char			*strcpy_with_spaces(char *src, int len);
bool			zero_helper(char c);
void			printer(t_data *data);
void			ft_lstclear(t_texture_info **lst);
void			ft_lstadd_back(t_texture_info **lst, t_texture_info *_new);
void			init_data(char *av, t_data **data);
char			**read_file(int *fd);
void			open_file(char *av, int *fd);
void			free_data(t_data *data);
void			skip_spaces(int *i, char **file);
t_texture_info	*ft_lstnew(void *id, void	*path);

void			parsing(t_data *data);
void			parse_file(char **file);
void			parse_map(t_data *data);
void			parse_colors(t_data *data);
void			extract_ppos(t_data **data);
void			extract_map(char **file, t_data **data);
void			extract_squared_map(t_data **data);
void			fill_t_struct(t_data **data);

#endif

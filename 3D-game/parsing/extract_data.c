/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:02:59 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/25 15:38:23 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_textures(char **file, t_data **data)
{
	int		i;
	int		c;
	char	**tmp;

	(1) && (i = 0, c = 0);
	while (file[i])
	{
		if (c == 4)
			break ;
		tmp = ft_split(file[i], ' ');
		if (c < 4 && ptr_counter(tmp) >= 3)
			(*data)->error = true;
		if (!ft_strcmp(tmp[0], "NO"))
			(1) && ((*data)->textures[0][1] = ft_strdup(tmp[1])), c++;
		else if (!ft_strcmp(tmp[0], "SO"))
			(1) && ((*data)->textures[1][1] = ft_strdup(tmp[1])), c++;
		else if (!ft_strcmp(tmp[0], "WE"))
			(1) && ((*data)->textures[2][1] = ft_strdup(tmp[1])), c++;
		else if (!ft_strcmp(tmp[0], "EA"))
			(1) && ((*data)->textures[3][1] = ft_strdup(tmp[1])), c++;
		ft_free(tmp);
		i++;
	}
	if (c != 4)
		(*data)->error = true;
}

void	extract_textures(char **file, t_data **data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*data)->textures[i] = (char **)malloc(sizeof(char *) * 3);
		(*data)->textures[i][0] = NULL;
		(*data)->textures[i][1] = NULL;
		(*data)->textures[i][2] = NULL;
		i++;
	}
	(*data)->textures[i] = NULL;
	(*data)->textures[0][0] = ft_strdup("NO");
	(*data)->textures[1][0] = ft_strdup("SO");
	(*data)->textures[2][0] = ft_strdup("WE");
	(*data)->textures[3][0] = ft_strdup("EA");
	fill_textures(file, data);
	fill_t_struct(data);
}

void	fill_colors(char **file, t_data **data)
{
	int		i;
	int		c;
	char	**tmp;

	(1) && (i = 0, c = 0);
	while (file[i])
	{
		if (c == 2)
			break ;
		tmp = ft_split(file[i], ' ');
		if (c < 2 && ptr_counter(tmp) >= 3)
			(*data)->error = true;
		small_parser(tmp, data, &c);
		ft_free(tmp);
		i++;
	}
	if (c != 2)
		(*data)->error = true;
}

void	extract_colors(char **file, t_data **data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		(*data)->colors[i] = (char **)malloc(sizeof(char *) * 3);
		(*data)->colors[i][0] = NULL;
		(*data)->colors[i][1] = NULL;
		(*data)->colors[i][2] = NULL;
		i++;
	}
	(*data)->colors[2] = NULL;
	(*data)->colors[0][0] = ft_strdup("F");
	(*data)->colors[1][0] = ft_strdup("C");
	fill_colors(file, data);
}

void	init_data(char *av, t_data **data)
{
	int		fd[2];
	char	**file;

	open_file(av, &fd[0]);
	(*data) = malloc(sizeof(t_data));
	if (!*data)
		return (write(2, "Can't allocate!\n", 16), exit(1));
	file = read_file(&fd[0]);
	parse_file(file);
	if (!data || !file)
		return (close(fd[0]), close(fd[1]), exit(1));
	(*data)->error = false;
	extract_map(file, data);
	extract_ppos(data);
	extract_squared_map(data);
	extract_textures(file, data);
	extract_colors(file, data);
	ft_free(file);
	if ((*data)->error)
	{
		write(2, "Error\nInvalide input.\n", 22);
		return (free_data(*data), exit(1));
	}
}

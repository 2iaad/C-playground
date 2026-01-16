/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:58:29 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/25 15:47:53 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_colors(char **file, int i, char *found, char *lost)
{
	char	**tmp;

	skip_spaces(&i, file);
	if (*found == 'F')
	{
		tmp = ft_split(file[i], ' ');
		if (!ft_strcmp(tmp[0], lost))
			return (true);
		else
			return (false);
	}
	return (false);
}

int	file_without_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i == 0)
	{
		write(2, "Error\nInvalide map.", 20);
		exit(1);
	}
	i -= 1;
	while (i > 0 && file[i][0] != '\n')
		i--;
	return (i);
}

void	texture_checker(int *k, char *texture)
{
	int	fd;

	(*k)++;
	if (texture[ft_strlen(texture) - 1] == '\n')
		texture[ft_strlen(texture) - 1] = '\0';
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	close(fd);
}

void	helper_fun(char **tmp, int *k)
{
	if (!ft_strcmp(tmp[0], "NO"))
		texture_checker(&k[0], tmp[1]);
	else if (!ft_strcmp(tmp[0], "SO"))
		texture_checker(&k[1], tmp[1]);
	else if (!ft_strcmp(tmp[0], "EA"))
		texture_checker(&k[2], tmp[1]);
	else if (!ft_strcmp(tmp[0], "WE"))
		texture_checker(&k[3], tmp[1]);
	else if (!ft_strcmp(tmp[0], "C"))
		k[4]++;
	else if (!ft_strcmp(tmp[0], "F"))
		k[5]++;
	else
	{
		write(2, "Error\nInvalide map.", 20);
		exit(1);
	}
}

void	parse_file(char **file)
{
	int			i;
	int			c;
	char		**tmp;
	static int	k[6] = {0};

	(1) && (i = -1), (c = file_without_map(file));
	while (file[++i])
	{
		skip_spaces(&i, file);
		if (i >= c)
			break ;
		tmp = ft_split(file[i], ' ');
		helper_fun(tmp, &k[0]);
		ft_free(tmp);
	}
	i = 0;
	while (i < 6)
	{
		if (k[i] != 1)
		{
			write(2, "Error\nInvalide map.", 20);
			exit(1);
		}
		i++;
	}
}

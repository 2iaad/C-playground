/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:31:57 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/30 21:47:19 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**two_d_array(int *fd, char *av)
{
	int		i;
	int		line;
	char	*s;
	char	**map;

	line = 0;
	i = -1;
	s = "1337";
	while (s)
	{
		s = get_next_line(*fd);
		free(s);
		line++;
	}
	map = (char **) malloc (sizeof(char *) * line);
	if (!map)
		return (NULL);
	close(*fd);
	*fd = open(av, O_RDONLY, 0644);
	while (++i < line)
		map[i] = get_next_line(*fd);
	return (close(*fd), map);
}

void	open_map(char **av, int *fd)
{
	*fd = open(av[1], O_RDONLY, 0644);
	if (*fd == -1)
	{
		perror("open");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	char	**str;

	if (ac < 2)
		exit(0);
	if (ac == 2 && !ft_strcmp(av[1], ".ber"))
	{
		open_map(av, &fd);
		str = two_d_array(&fd, av[1]);
		if (!str)
			return (1);
		parsing(str);
		path_check(str);
		mlx(str);
	}
	else
		write(2, "Enter a valide map file.", 24);
}

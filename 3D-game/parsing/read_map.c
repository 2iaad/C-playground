/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:19:05 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/23 05:16:24 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**read_file(int *fd)
{
	int		i;
	int		line;
	char	*s;
	char	**map;

	(1) && (line = 0), (i = -1), (s = "1337");
	while (s)
	{
		s = get_next_line(*fd);
		free(s);
		line++;
	}
	map = (char **) malloc (sizeof(char *) * line);
	if (!map)
		return (NULL);
	while (++i < line)
		map[i] = get_next_line(*(fd + 1));
	return (close(*fd), close(*(fd + 1)), map);
}

void	open_file(char *av, int *fd)
{
	*fd = open(av, O_RDONLY);
	*(fd + 1) = open(av, O_RDONLY);
	if (*fd == -1 || *(fd + 1) == -1)
	{
		perror("open");
		close(*fd);
		close(*(fd + 1));
		exit(1);
	}
}

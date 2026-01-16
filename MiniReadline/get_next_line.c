/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:39:17 by zderfouf          #+#    #+#             */
/*   Updated: 2024/01/18 09:18:54 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*preserve(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	new_str = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_str)
		return (free(str), str = NULL, NULL);
	i++;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (free(str), str = NULL, new_str);
}

char	*new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	return (line[i] = '\0', line);
}

char	*read_line(int fd, char *str)
{
	char	*tempo;
	int		read_return;

	read_return = 1;
	tempo = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!tempo)
		return (free(str), str = NULL, NULL);
	while (!ft_strchr(str, '\n') && read_return != 0)
	{
		read_return = read(fd, tempo, BUFFER_SIZE);
		if (read_return == -1)
			return (free(str), free(tempo), NULL);
		tempo[read_return] = '\0';
		str = ft_strjoin(str, tempo);
		if (!str)
			break ;
	}
	return (free (tempo), str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = new_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = preserve(str);
	return (line);
}

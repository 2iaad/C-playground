/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:43:22 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/12 16:43:50 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

void	ft_free(char **s_s)
{
	int	i;

	i = 0;
	while (s_s[i])
	{
		free(s_s[i]);
		i++;
	}
	free(s_s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int			i;
	static int	a;

	i = 0;
	if (size != 0)
	{
		while (src[i] && --size)
		{
			dest[a] = src[i];
			i++;
			a++;
		}
		dest[a++] = ' ';
	}
}

char	*join_arguments(char **av)
{
	int		i;
	int		len;
	char	*s;

	i = -1;
	len = 0;
	while (av[++i])
		len += ft_strlen(av[i]) + 1;
	s = (char *) malloc (sizeof(char) * len);
	if (!s)
		return (NULL);
	i = -1;
	while (av[++i])
		ft_strlcpy(s, av[i], ft_strlen(av[i]) + 1);
	s[len - 1] = '\0';
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

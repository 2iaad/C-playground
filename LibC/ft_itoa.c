/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:28 by zderfouf          #+#    #+#             */
/*   Updated: 2023/11/19 17:58:20 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		cn;
	char	*ptr;

	nb = n;
	cn = ft_countnumbers(nb);
	if (nb < 0)
	{
		nb *= -1;
		cn++;
	}
	ptr = (char *) malloc (sizeof(char) * (cn + 1));
	if (!ptr)
		return (NULL);
	ptr[cn] = '\0';
	while (cn-- > 0)
	{
		ptr[cn] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

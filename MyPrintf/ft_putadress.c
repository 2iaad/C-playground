/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:24:57 by zderfouf          #+#    #+#             */
/*   Updated: 2023/12/07 22:38:48 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa2(unsigned long n, int i)
{
	if (n >= 16)
		i = ft_puthexa2(n / 16, i);
	i += write(1, &(BASE[n % 16]), 1);
	return (i);
}

int	ft_putadress(void *n, int i)
{
	ft_putstr("0x", i);
	i = ft_puthexa2((unsigned long)n, i);
	return (i + 2);
}

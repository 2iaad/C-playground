/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:38:50 by zderfouf          #+#    #+#             */
/*   Updated: 2023/12/06 20:32:58 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c, int i)
{
	if (n >= 16)
		i = ft_puthexa(n / 16, c, i);
	if (c == 'x')
		i += write(1, &(BASE[n % 16]), 1);
	else if (c == 'X')
		i += write(1, &(UPPERBASE[n % 16]), 1);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:10 by zderfouf          #+#    #+#             */
/*   Updated: 2023/12/06 10:27:29 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int i)
{
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		i += write(1, str++, 1);
	}
	return (i);
}

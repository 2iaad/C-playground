/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:22 by zderfouf          #+#    #+#             */
/*   Updated: 2023/12/12 19:31:48 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(const char c, va_list ap, int count)
{
	if (c == 's')
		count = ft_putstr(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(ap, int), count);
	else if (c == 'x' || c == 'X')
		count = ft_puthexa(va_arg(ap, unsigned int), c, count);
	else if (c == 'u')
		count = ft_putunbr(va_arg(ap, unsigned int), count);
	else if (c == 'p')
		count = ft_putadress(va_arg(ap, void *), count);
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	if (write(1, "", 0) < 0)
		return (-1);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			count = formats(*str, ap, count);
		}
		else if (*str != '%')
			count += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

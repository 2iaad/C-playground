/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:38:58 by zderfouf          #+#    #+#             */
/*   Updated: 2023/12/12 19:31:51 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE "0123456789abcdef"
# define UPPERBASE "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str, int i);
int	ft_putchar(char c);
int	ft_putnbr(int nb, int i);
int	ft_putunbr(unsigned int n, int i);
int	ft_puthexa(unsigned int n, char c, int i);
int	ft_putadress(void *n, int i);

#endif

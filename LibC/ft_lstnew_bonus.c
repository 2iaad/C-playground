/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:41:57 by zderfouf          #+#    #+#             */
/*   Updated: 2023/11/24 19:42:03 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*nn;

	nn = (t_list *) malloc (sizeof(t_list));
	if (!nn)
		return (0);
	nn->content = cont;
	nn->next = NULL;
	return (nn);
}

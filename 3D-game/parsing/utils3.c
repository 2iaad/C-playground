/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:46:43 by zderfouf          #+#    #+#             */
/*   Updated: 2024/12/22 23:17:18 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_texture_info	*ft_lstnew(void *id, void	*path)
{
	t_texture_info	*nn;

	nn = (t_texture_info *) malloc (sizeof(t_texture_info));
	if (!nn)
		return (0);
	nn->id = id;
	nn->path = path;
	nn->next = NULL;
	return (nn);
}

int	ft_lstsize(t_texture_info *lst)
{
	int				nofn;
	t_texture_info	*ptr2n;

	nofn = 0;
	ptr2n = lst;
	if (ptr2n == NULL)
		return (0);
	while (ptr2n != NULL)
	{
		ptr2n = ptr2n->next;
		nofn++;
	}
	return (nofn);
}

t_texture_info	*ft_lstlast(t_texture_info *lst)
{
	t_texture_info	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	ft_lstadd_back(t_texture_info **lst, t_texture_info *new)
{
	t_texture_info	*lastnode;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
}

void	ft_lstclear(t_texture_info **lst)
{
	t_texture_info	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = (*lst);
	(*lst) = (*lst)->next;
	free(tmp);
	while (*lst)
		ft_lstclear(lst);
}

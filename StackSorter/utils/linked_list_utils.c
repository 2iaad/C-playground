/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:50:50 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/12 16:44:10 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

t_stack	*ft_lstnew(int number, int pos)
{
	t_stack	*nn;

	nn = malloc (sizeof(t_stack));
	if (!nn)
		return (0);
	nn->content = number;
	nn->index = pos;
	nn->next = NULL;
	return (nn);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*lastnode;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = node;
	}
}

void	ft_lstadd_front(t_stack **root, t_stack *neww)
{
	if (root && neww)
		neww->next = *root;
	if (neww)
		*root = neww;
}

int	ft_lstsize(t_stack *lst)
{
	int		nofn;
	t_stack	*ptr2n;

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

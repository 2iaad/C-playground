/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:17:48 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/12 17:35:55 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, int i)
{
	t_stack	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	ft_lstadd_front(lst, tmp);
	if (i == 0)
		write(1, "sa\n", 3);
	if (i == 1)
		write(1, "sb\n", 3);
	if (i == 2)
		write(1, "ss\n", 3);
}

void	rotate(t_stack **lst, int i)
{
	t_stack	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstadd_back(&tmp, *lst);
	*lst = tmp;
	if (i == 0)
		write(1, "ra\n", 3);
	if (i == 1)
		write(1, "rb\n", 3);
	if (i == 2)
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack **lst, int i)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(lst, ft_lstlast(*lst));
	tmp->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
	if (i == 1)
		write(1, "rrb\n", 4);
	if (i == 2)
		write(1, "rrr\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*b == NULL)
		return ;
	tmp = *b;
	tmp2 = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	*b = tmp2;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*a == NULL)
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	*a = tmp2;
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:17:48 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/12 16:51:29 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bonus/push_swap_bonus.h"

void	swap(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	ft_lstadd_front(lst, tmp);
}

void	rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstadd_back(&tmp,*lst);
	*lst = tmp;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	ft_lstadd_front(lst, ft_lstlast(*lst));
	tmp->next = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*b || !b)
		return ;
	tmp = *b;
	tmp2 = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	*b = tmp2;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*a || !a)
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	*a = tmp2;
}

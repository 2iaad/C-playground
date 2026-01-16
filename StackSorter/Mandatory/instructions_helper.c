/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:42:52 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:43:43 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack	**a, t_stack	**b)
{
	swap(a, 2);
	swap(b, 1337);
}

void	rr(t_stack **a, t_stack	**b)
{
	rotate(a, 2);
	rotate(b, 1337);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 1337);
}

void	sort_three_numbers(t_stack **a)
{
	if ((*a)->index < (*a)->next->index && (*a)->next->index
		> (*a)->next->next->index && (*a)->index < (*a)->next->next->index)
	{
		swap(a, 0);
		rotate(a, 0);
	}
	if ((*a)->index > (*a)->next->index && (*a)->next->index
		< (*a)->next->next->index && (*a)->index < (*a)->next->next->index)
		swap(a, 0);
	if ((*a)->index > (*a)->next->index && (*a)->next->index
		< (*a)->next->next->index && (*a)->index > (*a)->next->next->index)
		rotate(a, 0);
	if ((*a)->index > (*a)->next->index && (*a)->next->index
		> (*a)->next->next->index && (*a)->index > (*a)->next->next->index)
	{
		rotate(a, 0);
		swap(a, 0);
	}
	if ((*a)->index < (*a)->next->index && (*a)->next->index
		> (*a)->next->next->index && (*a)->index > (*a)->next->next->index)
		reverse_rotate(a, 0);
}

void	sort_four_numbers(t_stack **a, t_stack **b)
{
	while (1)
	{
		if ((*a)->index == 0)
			break ;
		reverse_rotate(a, 0);
	}
	pb(a, b);
	sort_three_numbers(a);
	pa(a, b);
}

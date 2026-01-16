/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:18:28 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/13 22:58:40 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_numbers(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a, b);
			i++;
		}
		reverse_rotate(a, 0);
	}
	if ((*b)->content < (*b)->next->content)
		swap(b, 1);
	sort_three_numbers(a);
	pa(a, b);
	pa(a, b);
}

bool	reverse_or_rotate_reverse(t_stack **b, int max)
{
	int		i;
	int		middle;
	t_stack	*tmp;

	i = 0;
	middle = ft_lstsize(*b) / 2;
	tmp = *b;
	while (tmp)
	{
		if (tmp->index == max)
			if (i < middle)
				return (true);
		tmp = tmp->next;
		i++;
	}
	return (false);
}

void	return_to_a(t_stack **a, t_stack **b)
{
	int	i;
	int	max;

	i = 1;
	max = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b)->index == max)
		{
			pa(a, b);
			max--;
		}
		else
		{
			if (reverse_or_rotate_reverse(b, max))
				rotate(b, 1);
			else
				reverse_rotate(b, 1);
		}
	}
}

void	sort_bigger_numbers(t_stack **a, t_stack **b)
{
	int	i;
	int	range;

	i = 0;
	if (ft_lstsize(*a) <= 100)
		range = 16;
	else
		range = 33;
	while (ft_lstsize(*a) != 0)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index < (i + range))
		{
			pb(a, b);
			rotate(b, 1);
			i++;
		}
		else
			rotate(a, 0);
	}
	return_to_a(a, b);
}

void	sorter(t_stack	**a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		if ((*a)->content > (*a)->next->content)
			swap(a, 0);
	if (ft_lstsize(*a) == 3)
		sort_three_numbers(a);
	if (ft_lstsize(*a) == 4)
		sort_four_numbers(a, b);
	if (ft_lstsize(*a) == 5)
		sort_five_numbers(a, b);
	if (ft_lstsize(*a) > 5)
		sort_bigger_numbers(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:12:48 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:34:21 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bonus/push_swap_bonus.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

bool	apply_instructions(t_stack **a, t_stack **b, char *s)
{
	if (!(ft_strncmp(s, "sa\n", 4)))
		swap(a);
	else if (!(ft_strncmp(s, "ra\n", 4)))
		rotate(a);
	else if (!(ft_strncmp(s, "rra\n", 5)))
		reverse_rotate(a);
	else if (!(ft_strncmp(s, "sb\n", 4)))
		swap(b);
	else if (!(ft_strncmp(s, "rb\n", 4)))
		rotate(b);
	else if (!(ft_strncmp(s, "rrb\n", 5)))
		reverse_rotate(b);
	else if (!(ft_strncmp(s, "pa\n", 4)))
		pa(a, b);
	else if (!(ft_strncmp(s, "pb\n", 4)))
		pb(a, b);
	else if (!(ft_strncmp(s, "ss\n", 4)))
		ss(a, b);
	else if (!(ft_strncmp(s, "rr\n", 4)))
		rr(a, b);
	else if (!(ft_strncmp(s, "rrr\n", 5)))
		rrr(a, b);
	else
		return (false);
	return (true);
}

void	read_instructions(t_stack **a)
{
	char	*s;
	t_stack	*b;

	b = NULL;
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!apply_instructions(a, &b, s))
		{
			free(s);
			ft_lstclear(a);
			ft_lstclear(&b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(s);
	}
	if (!arg_checker_if_sorted(*a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&b);
	ft_lstclear(a);
}

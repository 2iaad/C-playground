/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:29:02 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 18:05:19 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/utils.h"

bool	arg_checker_if_sorted(char **s);
bool	arg_checker_pure_numbers(char **s);
bool	arg_checker_repeated_numbers(char **s);
bool	arg_checker_if_integers(char **s);
bool	white_spaces_checker(char *av);
char	**parser(int ac, char **av);

void	sorter(t_stack **a, t_stack **b);
void	sort_three_numbers(t_stack **a);
void	sort_four_numbers(t_stack **a, t_stack **b);
void	sort_five_numbers(t_stack **a, t_stack **b);
void	sort_bigger_numbers(t_stack **a, t_stack **b);

bool	reverse_or_rotate_reverse(t_stack **b, int max);
void	return_to_a(t_stack **a, t_stack **b);

void	swap(t_stack **lst, int i);
void	rotate(t_stack **lst, int i);
void	reverse_rotate(t_stack **lst, int i);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif

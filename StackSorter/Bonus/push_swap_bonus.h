/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:37:45 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:34:49 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../utils/utils.h"
# include "../get_next_line/get_next_line.h"

bool	arg_checker_if_sorted(t_stack *a);
bool	arg_checker_pure_numbers(char **s);
bool	arg_checker_repeated_numbers(char **s);
bool	arg_checker_if_integers(char **s);
bool	white_spaces_checker(char *av);
char	**parser(int ac, char **av);

void	swap(t_stack **lst);
void	rotate(t_stack **lst);
void	reverse_rotate(t_stack **lst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	read_instructions(t_stack **a);
bool	apply_instructions(t_stack **a, t_stack **b, char *s);

#endif

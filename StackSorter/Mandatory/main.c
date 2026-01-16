/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:18:20 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:31:15 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_the_numbers(char **arguments, t_stack **a)
{
	t_stack	*current;
	int		i;
	int		j;

	current = *a;
	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[j])
		{
			if (ft_atol(arguments[i]) > ft_atol(arguments[j]))
				current->index++;
			j++;
		}
		i++;
		current = current->next;
	}
	ft_free(arguments);
}

t_stack	*linked_list_maker(char **arguments)
{
	int		i;
	int		k;
	t_stack	*a;
	char	**s;

	i = 0;
	a = NULL;
	while (arguments[i])
	{
		s = ft_split(arguments[i], ' ');
		k = 0;
		while (s[k])
		{
			ft_lstadd_back(&a, ft_lstnew((int)ft_atol(s[k]), 0));
			k++;
		}
		ft_free(s);
		i++;
	}
	return (a);
}

char	**second_parser(char **s_args)
{
	if (!arg_checker_pure_numbers(s_args)
		|| !arg_checker_repeated_numbers(s_args)
		|| !arg_checker_if_integers(s_args))
	{
		ft_free(s_args);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (arg_checker_if_sorted(s_args))
		exit(0);
	return (s_args);
}

char	**parser(int ac, char **av)
{
	char	*j_args;
	char	**s_args;

	s_args = NULL;
	if (ac > 2)
	{
		j_args = join_arguments(++av);
		s_args = ft_split(j_args, ' ');
		free(j_args);
	}
	else if (ac == 2)
		s_args = ft_split(av[1], ' ');
	if (!s_args)
		return (NULL);
	return (second_parser(s_args));
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	**parsed_args;

	i = 0;
	if (ac == 1)
		exit(0);
	while (av[++i])
	{
		if (!white_spaces_checker(av[i]))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	parsed_args = parser(ac, av);
	if (!parsed_args)
		return (1);
	a = linked_list_maker(parsed_args);
	indexing_the_numbers(parsed_args, &a);
	sorter(&a, &b);
	ft_lstclear(&a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:21:15 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 14:32:36 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	read_instructions(&a);
}

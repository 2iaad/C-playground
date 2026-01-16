/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:15:31 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/14 19:35:56 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_stack;

int		ft_strlen(char *s);
void	ft_free(char **s_s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_strlcpy(char *dest, const char *src, size_t size);
long	ft_atol(const char *str);
char	*join_arguments(char **av);
char	**ft_split(const char *s, char c);
long	ft_atol(const char *str);

t_stack	*linked_list_maker(char **s);
t_stack	*ft_lstnew(int number, int position);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
void	ft_lstadd_front(t_stack **root, t_stack *neww);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **t_stack);

#endif

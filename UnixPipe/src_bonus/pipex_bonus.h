/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:13:19 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/04 16:52:14 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../get_next_line/get_next_line.h"

int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t	n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(const char *s, char c);

void	pipex(char *cmd, char **env);
int		normal_file_opener(int a, char *file);
void	heredoc_limiter(char **av, int ac);
void	heredoc_file_opener(int ac, char **av);
void	first_child(char **av, char **ev);
void	error(char *str, int a);
void	ft_free(char **tab);
char	*look_for_paths(char **env);
char	*right_path(char *cmd, char **env);
void	execute_cmd(char *cmd, char **env);

#endif

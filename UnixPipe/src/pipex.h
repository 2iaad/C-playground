/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:30:28 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/04 11:54:42 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
void	error(char *str, int exit_value);
void	first_childd(char **av, char **ev, int *fds);
void	second_child(char **av, char **ev, int *fds);
void	ft_free(char **s);
char	*look_for_paths(char **ev);
char	*right_path(char *cmd, char **env);
void	execute_cmd(char *cmd, char **env);
void	close_and_wait(int a, int b, int *fds);

#endif

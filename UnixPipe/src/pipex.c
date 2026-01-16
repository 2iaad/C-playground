/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:00:49 by zderfouf          #+#    #+#             */
/*   Updated: 2024/03/04 11:36:18 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str, int a)
{
	if (a == 1)
		ft_putstr_fd (str, 2);
	else
		perror (str);
	exit (1);
}

void	second_child(char **av, char **ev, int *fds)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror ("open");
	dup2(fd, 1);
	close(fd);
	close(fds[1]);
	dup2(fds[0], 0);
	close (fds[0]);
	execute_cmd(av[3], ev);
}

void	first_childd(char **av, char **ev, int *fds)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("./pipex: no such file or directory: ", 2);
		ft_putendl_fd(av[1], 2);
		exit(1);
	}
	dup2(fd, 0);
	close(fd);
	close(fds[0]);
	dup2(fds[1], 1);
	close(fds[1]);
	execute_cmd(av[2], ev);
}

int	main(int ac, char **av, char **env)
{
	int	fds[2];
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (ac != 5)
		error("Try this: ./pipex infile cmd cmd outfile", 1);
	if (pipe(fds) == -1)
		error("pipe", 0);
	a = fork();
	if (a == -1)
		error("fork", 0);
	if (a == 0)
		first_childd(av, env, fds);
	else
	{
		b = fork();
		if (b == -1)
			error("fork", 0);
		if (b == 0)
			second_child(av, env, fds);
	}
	close_and_wait(a, b, fds);
}

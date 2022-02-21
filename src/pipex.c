/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:50:21 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/21 11:47:46 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error(errno, argv[1]);
	dup2 (fd[1], STDOUT_FILENO);
	dup2 (filein, STDIN_FILENO);
	close (fd[0]);
	close (filein);
	ft_execute (argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_error(errno, argv[4]);
	dup2 (fd[0], STDIN_FILENO);
	dup2 (fileout, STDOUT_FILENO);
	close (fd[1]);
	close (fileout);
	ft_execute (argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{	
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error(errno, "pipe");
		pid = fork();
		if (pid == -1)
			ft_error(errno, "fork");
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Wrong number of arguments\n\e[0m", 2);
	}
	return (0);
}

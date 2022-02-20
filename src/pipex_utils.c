/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:51:45 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/20 19:46:24 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int exit_code, char *argv)
{	
	if (exit_code == -1)
	{
		ft_putstr_fd("command not found : ", 2);
		ft_putstr_fd(argv, 2);
		exit(1);
	}
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*path_without_cmd;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_without_cmd = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_without_cmd, cmd);
		free(path_without_cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = ft_find_path(cmd[0], envp);
	// if (!path) //
	// {
	// 	while (cmd[i])
	// 	{
	// 		free (cmd[i]);
	// 		i++;
	// 	}
	// 	free (cmd);
	// 	ft_error (errno);
	// }
	if (execve(path, cmd, envp) == -1)
		ft_error (-1);
}

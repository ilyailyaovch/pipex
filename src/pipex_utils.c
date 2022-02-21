/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:51:45 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/21 19:10:51 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int exit_code, char *argv)
{
	if (exit_code == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(strerror(exit_code), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_clear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*path_without_cmd;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", 1) != NULL)
		return (cmd);
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_without_cmd = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_without_cmd, cmd);
		free(path_without_cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_clear(paths);
			return (path);
		}
		i++;
	}
	return (cmd);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = ft_find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		ft_error (-1, argv);
	free(path);
	ft_clear(cmd);
}

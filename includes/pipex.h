/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:50:16 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/20 19:46:37 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

/*	lib_1.c */
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*	lib_2.c */
char	**ft_split(char const *s, char c);

/*	pipex_utils.c */
void	ft_error(int exit_code, char *argv);
char	*ft_find_path(char *cmd, char **envp);
void	ft_execute(char *argv, char **envp);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:27:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/20 18:17:07 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_free_elem(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		free (str[i++]);
	free (str);
	return (NULL);
}

static unsigned int	ft_numb_of_words(char const *s, char c)
{
	unsigned int	coun;
	unsigned int	nb;

	if (!s[0])
		return (0);
	coun = 0;
	nb = 0;
	while (s[coun] && s[coun] == c)
		coun++;
	while (s[coun])
	{
		if (s[coun] == c)
		{
			nb++;
			while (s[coun] && s[coun] == c)
				coun++;
			continue ;
		}
		coun++;
	}
	if (s[coun - 1] != c)
		nb++;
	return (nb);
}

static void	ft_str_small(char **s, unsigned int *len, char c)
{
	unsigned int	coun;

	coun = 0;
	*s += *len;
	*len = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[coun])
	{
		if ((*s)[coun] == c)
			return ;
		(*len)++;
		coun++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	coun;

	coun = 0;
	if ((int)size == 0)
		return (ft_strlen((char *)src));
	while ((src[coun] != '\0') && (coun < size - 1))
	{
		dst[coun] = src[coun];
		coun++;
	}
	dst[coun] = '\0';
	return (ft_strlen((char *)src));
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	coun;
	unsigned int	len_new;
	char			*str_new_start;

	if (!s)
		return (NULL);
	str_new_start = (char *)s;
	len_new = 0;
	coun = 0;
	str = (char **)malloc(sizeof(char *) * (ft_numb_of_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (coun < ft_numb_of_words(s, c))
	{
		ft_str_small(&str_new_start, &len_new, c);
		str[coun] = (char *)malloc(sizeof(char) * (len_new + 1));
		if (!str[coun])
			return (ft_free_elem(str));
		ft_strlcpy(str[coun], (const char *)str_new_start, len_new + 1);
		coun++;
	}
	str[coun] = NULL;
	return (str);
}

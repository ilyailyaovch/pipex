/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:30:25 by pleoma            #+#    #+#             */
/*   Updated: 2022/02/20 18:16:58 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, &(*s), 1);
		s++;
	}
}

int	ft_strlen(char *str)
{
	unsigned int	coun;

	coun = 0;
	while (str[coun] != '\0')
	{
		coun++;
	}
	return (coun);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	coun1;
	unsigned int	coun2;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	coun1 = 0;
	coun2 = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[coun1])
	{
		dst[coun1] = s1[coun1];
		coun1++;
	}
	while (s2[coun2])
	{
		dst[coun1 + coun2] = s2[coun2];
		coun2++;
	}
	dst[coun1 + coun2] = '\0';
	return (dst);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	coun_b;
	size_t	coun_l;

	coun_b = 0;
	coun_l = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[coun_b] != '\0')
	{
		if (big[coun_b] == little[0])
		{
			while ((big[coun_b + coun_l] == little[coun_l])
				&& (little[coun_l] != '\0') && (coun_b + coun_l < len))
				coun_l++;
			if (little[coun_l] == '\0')
				return ((char *)&big[coun_b]);
		}
		coun_b++;
	}
	return (NULL);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:21:26 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/18 23:53:42 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	find_nl(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
/*
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len] != '\0')
			len++;
	}
	return (len);
}*/

/*size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}*/

void	initialise_stash(char **stash)
{
	if (!(*stash))
	{
		*stash = malloc(1);
		if (!*(stash))
			return ;
		(*stash)[0] = '\0';
	}
}
/*char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return ((char*)NULL);
}*/
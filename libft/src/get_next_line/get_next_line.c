/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:21:36 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/18 23:53:25 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	fill_stash(int fd, char **stash)
{
	int		bytes_read;
	char	*buf;
	char	*temp;

	bytes_read = 1;
	initialise_stash(stash);
	while (!(ft_strchr(*stash, '\n')) && bytes_read > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buf);
		free(*stash);
		*stash = temp;
		free(buf);
	}
}

void	extract_stash_line(char *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	*line = malloc(sizeof(char) * (len + 1));
	if (!(*line))
		return ;
	i = 0;
	while (i < len)
	{
		(*line)[i] = stash[i];
		i++;
	}
	(*line)[i] = '\0';
}

void	clean_stash(char **stash)
{
	size_t	i;
	size_t	len;
	char	*new_stock;

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	if ((*stash)[len] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	new_stock = malloc((ft_strlen(*stash) - len + 1));
	if (!new_stock)
		return ;
	i = 0;
	while ((*stash)[len])
		new_stock[i++] = (*stash)[len++];
	new_stock[i] = '\0';
	free(*stash);
	*stash = new_stock;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd == -19 && stash)
		{
			free(stash);
			stash = NULL;
		}
	}
	fill_stash(fd, &stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	extract_stash_line(stash, &line);
	clean_stash(&stash);
	return (line);
}

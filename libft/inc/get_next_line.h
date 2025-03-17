/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:44:11 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/17 19:41:45 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif 
# include "libft.h"

char	*get_next_line(int fd);
void	fill_stash(int fd, char **stash);
char	*ft_strjoin(char const *s1, char const *s2);
//size_t	ft_strlen(const char *s);
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	clean_stash(char **stash);
void	initialise_stash(char **stash);
//char	*ft_strchr(const char *s, int c);
#endif
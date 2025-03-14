/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:15:08 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/14 22:18:13 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *str, ...);
int	check(const char str, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_0xputpointer(unsigned long long nb, int flag);
int	ft_putpointer(unsigned long long nb, int flag);
int	ft_putnbr(int nb);
int	ft_hex(unsigned int nb, int flag);
int	ft_unsignednb(unsigned int nb);

#endif
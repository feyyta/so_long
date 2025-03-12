/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:14:38 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/12 23:14:39 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char str, va_list arg)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (str == 'p')
		count += ft_putptr(va_arg(arg, void *));
	else if (str == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (str == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (str == 'u')
		count += ft_putunsigned(va_arg(arg, unsigned int));
	else if (str == 'x')
		count += ft_putnbr_hex('x', va_arg(arg, int));
	else if (str == 'X')
		count += ft_putnbr_hex('X', va_arg(arg, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			arg;
	unsigned int	i;

	va_start(arg, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				i += check_arg(*str, arg);
			else if (*str == '%')
				i += ft_putchar('%');
			str++;
		}
		else
		{
			i += ft_putchar(*str);
			str++;
		}
	}
	va_end(arg);
	return (i);
}

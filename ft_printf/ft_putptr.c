/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:15:19 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/12 23:15:20 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_ptr(unsigned long nbr)
{
	char	hex[17];
	int		count;

	count = 0;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	if (nbr <= 15)
		count += ft_putchar(hex[nbr]);
	else
	{
		count += ft_putnbr_hex_ptr(nbr / 16);
		count += ft_putnbr_hex_ptr(nbr % 16);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	value;
	int				count;

	value = (unsigned long)ptr;
	count = 0;
	if (value == 0)
		return (count += ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_hex_ptr(value);
	return (count);
}

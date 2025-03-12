/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:15:07 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/12 23:15:08 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(char c, unsigned int n)
{
	char	hex[17];
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (c == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	if (c == 'X')
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	if (nbr <= 15)
		count += ft_putchar(hex[nbr]);
	else
	{
		count += ft_putnbr_hex(c, nbr / 16);
		count += ft_putnbr_hex(c, nbr % 16);
	}
	return (count);
}

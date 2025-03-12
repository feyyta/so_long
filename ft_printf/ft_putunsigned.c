/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:15:29 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/12 23:15:30 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		count += ft_putchar(nbr);
	}
	else
	{
		count += ft_putunsigned(nbr / 10);
		count += ft_putunsigned(nbr % 10);
	}
	return (count);
}

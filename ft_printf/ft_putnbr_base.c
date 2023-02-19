/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:28:08 by pedgonca          #+#    #+#             */
/*   Updated: 2022/11/01 12:43:55 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(long long int nbr, char *base, int base_size)
{
	char	nbr_c[32];
	int		i;
	int		len;

	if (nbr == 0)
		return (ft_putchar('0'));
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len += ft_putchar('-');
	}
	i = 0;
	while (nbr > 0)
	{
		nbr_c[i++] = base[nbr % base_size];
		nbr /= base_size;
	}
	while (--i >= 0)
		len += ft_putchar(nbr_c[i]);
	return (len);
}

int	putnbr_base_p(unsigned long nbr)
{
	char	nbr_c[32];
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (nbr > 0)
	{
		nbr_c[i++] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	while (--i >= 0)
		len += ft_putchar(nbr_c[i]);
	return (len);
}

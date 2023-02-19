/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:52:00 by pedgonca          #+#    #+#             */
/*   Updated: 2022/11/04 13:45:16 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_p(unsigned long n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	return (write(1, "0x", 2) + putnbr_base_p(n));
}

static int	print_specvalue(char s, va_list arg)
{
	if (s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (s == 'p')
		return (ft_printf_p(va_arg(arg, long int)));
	if (s == 'd' || s == 'i')
		return (putnbr_base(va_arg(arg, int), "0123456789", 10));
	if (s == 'u')
		return (putnbr_base(va_arg(arg, unsigned int), "0123456789", 10));
	if (s == 'x')
		return (putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", 16));
	if (s == 'X')
		return (putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 16));
	if (s == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		counter;
	int		i;
	va_list	arg;

	va_start(arg, s);
	if (!*s)
		return (-1);
	counter = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (!*(s + 1))
				return (-1);
			i = print_specvalue(*(s++ + 1), arg);
			if (i < 0)
				return (-1);
			counter += i;
		}
		else
			counter += write(1, s, 1);
		s++;
	}
	va_end(arg);
	return (counter);
}

/* #include <stdio.h>

int main()
{
	//ft_printf("%d\n", ft_printf("%s%d\n", "hey", -56));
	int n = 5;
	int result;
	//char	*s = NULL;

	(void) n;
	result = printf("%u\n", 2);
	printf("built-in: %d\n", result);
	result = ft_printf("%u\n", 0);
	printf("minha: %d\n", result);
	(void) result;
	
} */

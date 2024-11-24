/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:07 by achemlal          #+#    #+#             */
/*   Updated: 2024/11/24 19:05:06 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, char c)
{
	int	res;

	if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(args, int));
	if (c == 's')
		res = ft_putstr(va_arg(args, char *));
	if (c == 'c')
		res = ft_putchar(va_arg(args, int));
	if (c == 'u')
		res = ft_unsigned_putnbr(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		res = ft_puthex(va_arg(args, int), c);
	if (c == 'p')
		res = ft_putstr("0x") + ft_putadr(va_arg(args, unsigned long));
	if (c == '%')
		res = ft_putchar('%');
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				res += ft_check(args, str[++i]);
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (res);
}

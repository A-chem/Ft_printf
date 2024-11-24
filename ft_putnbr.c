/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:23:07 by achemlal          #+#    #+#             */
/*   Updated: 2024/11/24 19:06:18 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		res;
	long	n;

	n = (long)nb;
	res = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		res += ft_putchar('-');
		nb = -n;
	}
	if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
		res += ft_putnbr(nb % 10);
	}
	else
		res += ft_putchar(nb + '0');
	return (res);
}

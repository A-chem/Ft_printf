/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:20:56 by achemlal          #+#    #+#             */
/*   Updated: 2024/11/21 11:22:49 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr(unsigned long long nb)
{
	int		res;
	char	*base;

	res = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		res += ft_putadr(nb / 16);
		res += ft_putadr(nb % 16);
	}
	else
		res += ft_putchar(base[nb % 16]);
	return (res);
}

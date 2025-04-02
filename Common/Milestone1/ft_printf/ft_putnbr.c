/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:58:12 by bakpulat          #+#    #+#             */
/*   Updated: 2024/12/18 11:45:33 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	r;

	r = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		r += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		r += ft_putnbr(nb / 10);
		r += ft_putnbr(nb % 10);
	}
	else
		r += ft_putchar(nb + 48);
	return (r);
}

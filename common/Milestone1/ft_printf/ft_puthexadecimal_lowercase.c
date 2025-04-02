/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal_lowercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:57:58 by bakpulat          #+#    #+#             */
/*   Updated: 2024/12/18 11:39:46 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadecimal_lowercase(unsigned int nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re += ft_puthexadecimal_lowercase(nb / 16);
		re += ft_puthexadecimal_lowercase(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}

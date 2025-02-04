/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:08:24 by bakpulat          #+#    #+#             */
/*   Updated: 2024/12/18 12:02:17 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putptr(unsigned long long c)
{
	int	re;

	re = 0;
	if (c == 0)
		re = ft_putstr("(nil)");
	else
	{
		re = ft_putstr("0x");
		re += ft_putadress(c);
	}
	return (re);
}

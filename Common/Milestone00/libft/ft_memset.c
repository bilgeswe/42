/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:19:14 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 20:13:01 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int a, size_t s)
{
	size_t	i;

	i = 0;
	while (i < s)
	{
		((unsigned char *)(ptr))[i] = a;
		i++;
	}
	return (ptr);
}

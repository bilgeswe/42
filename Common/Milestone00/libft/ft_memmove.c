/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:22:04 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 19:34:59 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_c;
	char	*dst_c;
	size_t	i;

	src_c = (char *)src;
	dst_c = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (len == 0 || dst == src)
		return (dst);
	if (dst_c > src_c)
		while (len-- > 0)
			dst_c[len] = src_c[len];
	else
	{
		while (i < len)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}

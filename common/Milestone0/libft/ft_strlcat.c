/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:18:20 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 20:14:40 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	i = 0;
	lensrc = 0;
	lendst = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	while (dst[lendst] != '\0' && lendst < dstsize)
		lendst++;
	if (dstsize <= lendst)
		return (dstsize + lensrc);
	while (src[i] != '\0' && (lendst + i < dstsize - 1))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}

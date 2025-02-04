/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:32:14 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 20:12:26 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	sub_len;

	i = 0;
	s_len = ft_strlen(s);
	sub_len = s_len - start;
	if (!s)
		return (0);
	if (s_len <= start)
		return (ft_strdup(""));
	if (sub_len > len)
		sub_len = len;
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!substr)
		return (substr);
	while (i < sub_len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

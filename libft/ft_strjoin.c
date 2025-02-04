/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:56 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 20:22:10 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	newstr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while ((i < len1) && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while ((i < len2) && s2[i] != '\0')
	{
		newstr[len1 + i] = s2[i];
		i++;
	}
	return ((newstr[len1 + len2] = '\0'), newstr);
}

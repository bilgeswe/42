/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:24:32 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/08 20:08:38 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence = NULL;
	int			counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == (unsigned char)c)
			last_occurrence = &s[counter];
		counter++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[counter]);
	return ((char *)last_occurrence);
}

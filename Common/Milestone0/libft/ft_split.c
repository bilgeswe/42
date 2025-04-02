/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:45:45 by bakpulat          #+#    #+#             */
/*   Updated: 2024/11/13 15:06:19 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_free_split(char **tab, int tab_index)
{
	while (tab_index--)
		free(tab[tab_index]);
	free(tab);
}

static char	**ft_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		k;
	int		tab_index;

	i = 0;
	tab_index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > k)
		{
			tab[tab_index] = ft_substr(s, k, i - k);
			if (!tab[tab_index++])
			{
				ft_free_split(tab, tab_index);
				return (NULL);
			}
		}
	}
	tab[tab_index] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(tab, s, c));
}

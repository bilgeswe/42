/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:14:16 by bakpulat          #+#    #+#             */
/*   Updated: 2025/01/14 20:45:43 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_after_line(char *bf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (bf[i] != '\0' && bf[i] != '\n')
		i++;
	if (!bf[i])
	{
		free (bf);
		return (NULL);
	}
	str = malloc(ft_strlen(bf) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (bf[i])
		str[j++] = bf[i++];
	str[j] = '\0';
	free (bf);
	return (str);
}

char	*ft_one_line(char	*bf)
{
	int		i;
	char	*line;

	i = 0;
	while (bf[i] != '\n' && bf[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (bf[i] != '\n' && bf[i] != '\0')
	{
		line[i] = bf[i];
		i++;
	}
	if (bf[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_find_n(char	*bf, int fd)
{
	char	*line;
	ssize_t	r;

	line = ft_calloc(1, BUFFER_SIZE + 1);
	r = 1;
	while (!ft_strchr(line, '\n') && r > 0)
	{
		r = read(fd, line, BUFFER_SIZE);
		if (r == -1 || (r == 0 && (!bf || *bf == '\0')))
		{
			free (line);
			free (bf);
			return (NULL);
		}
		line[r] = '\0';
		bf = ft_strjoin(bf, line);
	}
	free (line);
	return (bf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bf = ft_find_n(bf, fd);
	if (!bf)
	{
		free (bf);
		return (NULL);
	}
	line = ft_one_line(bf);
	bf = ft_after_line(bf);
	return (line);
}

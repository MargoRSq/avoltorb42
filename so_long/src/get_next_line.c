/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:05:46 by avoltorb          #+#    #+#             */
/*   Updated: 2022/03/03 12:50:13 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *cache, int fd)
{
	char	*buf;
	int		b_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buf);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buf[b_read] = '\0';
		cache = ft_strjoin(cache, buf);
		if (ft_strchr(cache, '\n'))
			break ;
	}
	free(buf);
	return (cache);
}

char	*ft_next_line(char *cache)
{
	int		nidx;
	char	*next_line;

	next_line = NULL;
	nidx = 0;
	if (cache[nidx])
	{
		while (cache[nidx] && cache[nidx] != '\n')
			nidx++;
		nidx++;
		next_line = (char *)malloc(sizeof(char) * (nidx + 1));
		if (!next_line)
			return (NULL);
		ft_strncpy(next_line, cache, nidx);
		next_line[nidx] = '\0';
	}
	return (next_line);
}

char	*ft_trim_line(char *cache)
{
	int		nidx;
	int		new_len;
	char	*new_cache;

	new_cache = NULL;
	nidx = 0;
	if (cache[nidx])
	{
		while (cache[nidx] && cache[nidx] != '\n')
			nidx++;
		new_len = ft_strlen(&cache[nidx + 1]);
		if (cache[nidx] == '\0' || new_len == 0)
		{
			free(cache);
			return (NULL);
		}
		new_cache = (char *)malloc(sizeof(char) * (new_len + 1));
		if (!new_cache)
			return (NULL);
		new_cache[new_len] = '\0';
		ft_strncpy(new_cache, &cache[nidx + 1], new_len);
		free(cache);
	}
	return (new_cache);
}

char	*get_next_line(int fd, char *line)
{
	static char	*cache;
	char		*next_line;

	if (line)
		free(line);
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	cache = ft_read(cache, fd);
	if (cache)
	{
		next_line = ft_next_line(cache);
		cache = ft_trim_line(cache);
		return (next_line);
	}
	return (NULL);
}

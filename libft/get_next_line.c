/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:26:22 by stales            #+#    #+#             */
/*   Updated: 2022/05/12 14:53:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_read(int fd, char *buf)
{
	char	*tmp;
	int		bytes;

	if (!buf)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_memochr(buf, '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		tmp[bytes] = 0;
		buf = ft_memojoin(buf, tmp);
	}
	free(tmp);
	tmp = NULL;
	if (bytes < 0 || !*buf)
	{
		free(buf);
		buf = NULL;
	}
	return (buf);
}

char	*ft_stash(char *s)
{
	char	*new;
	char	*start;
	char	*tmp;

	if (!s)
		return (NULL);
	start = ft_memochr(s, '\n');
	if (!start)
		return (NULL);
	new = (char *)malloc((ft_len(s) - (start - s)) + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (*start)
		*tmp++ = *start++;
	*tmp = 0;
	free(s);
	s = NULL;
	return (new);
}

char	*ft_line(char *buf)
{
	char	*tmp;
	char	*new;
	char	*end;

	end = ft_memochr(buf, '\n');
	if (!end)
		return (buf);
	new = (char *)malloc(end - buf + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (buf < end)
		*tmp++ = *buf++;
	*tmp = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buf)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = 0;
	}
	buf = ft_read(fd, buf);
	if (buf == NULL)
	{
		free(buf);
		buf = NULL;
	}
	line = ft_line(buf);
	buf = ft_stash(buf);
	return (line);
}

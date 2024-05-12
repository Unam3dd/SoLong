/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:19:33 by stales            #+#    #+#             */
/*   Updated: 2022/05/12 14:51:50 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_len(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

char	*ft_memochr(char *buf, unsigned char c)
{
	if (!buf)
		return (NULL);
	while (*buf && *buf != c)
		buf++;
	if (!*buf)
		return (NULL);
	return (++buf);
}

char	*ft_memojoin(char *s1, char *s2)
{
	char	*new;
	char	*tmp;
	char	*save;

	new = (char *)malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!new)
		return (NULL);
	*new = 0;
	save = new;
	tmp = s1;
	while (*tmp)
		*new++ = *tmp++;
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	while (new && *s2)
		*new++ = *s2++;
	*new = 0;
	return (save);
}

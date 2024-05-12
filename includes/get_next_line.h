/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:19:47 by stales            #+#    #+#             */
/*   Updated: 2022/05/12 14:52:13 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# ifndef MAX_FD
#  define MAX_FD 0x400
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_len(char *s);
char		*ft_memochr(char *buf, unsigned char c);
char		*ft_memojoin(char *s1, char *s2);
char		*ft_stash(char *s);
char		*ft_read(int fd, char *buf);
char		*ft_line(char *buf);
char		*get_next_line(int fd);

#endif

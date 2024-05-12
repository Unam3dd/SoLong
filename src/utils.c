/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:28:49 by stales            #+#    #+#             */
/*   Updated: 2022/05/14 12:19:37 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <unistd.h>

//////////////////////////////////
//
//			UTILS
//
//////////////////////////////////

int	ft_strnchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_readitems(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
		if (*s++ == c)
			i++;
	return (i);
}

void	ft_check_player(t_game *game, int line)
{
	char	*tmp;

	tmp = ft_strchr(game->map[line], 'P');
	while (tmp)
	{
		if (!game->flag[0])
		{
			game->x = ft_strnchr(game->map[line], 'P');
			game->y = line;
			game->flag[0] = 1;
		}
		*tmp = '0';
		tmp = ft_strchr(tmp + 1, 'P');
	}
}

void	force_readline(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		game->map[game->col++] = line;
		line = get_next_line(game->fd);
	}
	close(game->fd);
}

void	ft_put(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * 64, y * 64);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:30:14 by stales            #+#    #+#             */
/*   Updated: 2022/05/14 12:20:08 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	check_filename(const char *f)
{
	int	l;

	l = ft_strlen(f);
	return (f[l - 1] == 'r' && f[l - 2] == 'e'
		&& f[l - 3] == 'b' && f[l - 4] == '.');
}

int	read_map(t_game *game)
{
	char	*ln;

	ln = get_next_line(game->fd);
	if (!ln)
		return (game->err = ERR_FILE_EMPTY, 1);
	game->row = ft_strlen(ln);
	if ((int)ft_strspn(ln, "1") != game->row - 1)
		return (game->map[game->col++] = ln,
			game->err = ERR_FILE_MAPNOCOR, 1);
	while (ln)
	{
		if (ft_strlen(ln) != game->row)
			return (game->map[game->col++] = ln,
				game->err = ERR_FILE_SIZEMAP, 1);
		ln[game->row - 1] = 0;
		game->map[game->col++] = ln;
		ln = get_next_line(game->fd);
	}
	if ((int)ft_strspn(game->map[game->col - 1], "1") != game->row - 1)
		return (game->err = ERR_FILE_MAPNOCOR, 1);
	if (check_map(game))
		return (game->err = ERR_FILE_CTX, 1);
	return (ln = NULL, 0);
}

int	parse_map(t_game *game, const char *filename)
{
	if (!check_filename(filename))
		return (game->err = ERR_FILE_EXT, 1);
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		return (game->err = ERR_FILE_NOTFOUND, 1);
	if (read_map(game))
		return (1);
	return (close(game->fd));
}

int	check_map(t_game *game)
{
	int		i;

	i = 1;
	while (game->map[i] && i < game->col)
	{
		if (game->map[i][0] == '1' && game->map[i][game->row - 1] == '1')
			return (game->err = ERR_FILE_BORDER, 1);
		if ((int)ft_strspn(game->map[i], "01CEP") != game->row - 1)
			return (game->err = ERR_FILE_UNKNOWN, 1);
		ft_check_player(game, i);
		if (ft_strchr(game->map[i], 'C'))
		{
			game->flag[1] = 1;
			game->items += ft_readitems(game->map[i], 'C');
		}
		if (!game->flag[2] && ft_strchr(game->map[i], 'E'))
			game->flag[2] = 1;
		i++;
	}
	return (!game->flag[0] || !game->flag[1] || !game->flag[2]);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->col && game->map[i])
	{
		free(game->map[i]);
		game->map[i++] = NULL;
	}
}

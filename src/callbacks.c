/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:09:34 by stales            #+#    #+#             */
/*   Updated: 2022/05/14 12:16:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	hook_key(int k, t_mlx *mlx)
{
	char	*ptr;

	if (k == 113 || k == 65307)
		finish_the_mega_game(mlx);
	else if (k == 0x77 || k == 0x73 || k == 0x64 || k == 0x61)
	{
		move_player(mlx, k);
		mlx->game.move++;
		draw_map(mlx);
		ptr = ft_itoa(mlx->game.move);
		mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFF0000, ptr);
		free(ptr);
		ptr = NULL;
	}
	return (0);
}

int	finish_the_mega_game(t_mlx *mlx)
{
	free_images(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free_map(&mlx->game);
	free(mlx->mlx);
	mlx->win = NULL;
	mlx->mlx = NULL;
	exit(0);
}

void	move_player(t_mlx *mlx, int k)
{
	int	x;
	int	y;

	x = mlx->game.x;
	y = mlx->game.y;
	if ((k == 0x77 && mlx->game.map[y - 1][x] == '1')
		|| (k == 0x73 && mlx->game.map[y + 1][x] == '1')
		|| (k == 0x64 && mlx->game.map[y][x + 1] == '1')
		|| (k == 0x61 && mlx->game.map[y][x - 1] == '1'))
		return ;
	if (k == 0x77)
		mlx->game.y--;
	else if (k == 0x73)
		mlx->game.y++;
	else if (k == 0x64)
		mlx->game.x++;
	else if (k == 0x61)
		mlx->game.x--;
}

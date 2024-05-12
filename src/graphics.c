/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:43:52 by stales            #+#    #+#             */
/*   Updated: 2022/05/14 11:31:43 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stddef.h>
#include <stdlib.h>

void	so_long(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->game.row * 64;
	y = mlx->game.col * 64;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, x - 64, y, "Pepo");
	init_images(mlx);
	mlx_key_hook(mlx->win, hook_key, mlx);
	mlx_hook(mlx->win, 17, (1L << 17), finish_the_mega_game, mlx);
	draw_map(mlx);
	mlx_loop(mlx->mlx);
}

void	init_images(t_mlx *mlx)
{
	int	i;

	i = 64;
	mlx->img[0] = mlx_xpm_file_to_image(mlx->mlx, "dataset/floor.xpm", &i, &i);
	mlx->img[1] = mlx_xpm_file_to_image(mlx->mlx, "dataset/wall.xpm", &i, &i);
	mlx->img[2] = mlx_xpm_file_to_image(mlx->mlx, "dataset/exit.xpm", &i, &i);
	mlx->img[3] = mlx_xpm_file_to_image(mlx->mlx, "dataset/player.xpm", &i, &i);
	mlx->img[4] = mlx_xpm_file_to_image(mlx->mlx, "dataset/banana.xpm", &i, &i);
}

void	free_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(mlx->mlx, mlx->img[i++]);
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->game.col)
	{
		j = 0;
		while (j < mlx->game.row - 1)
		{
			if (mlx->game.map[i][j] == '0')
				ft_put(mlx, mlx->img[0], j, i);
			else if (mlx->game.map[i][j] == '1')
				ft_put(mlx, mlx->img[1], j, i);
			else if (mlx->game.map[i][j] == 'E')
				ft_put(mlx, mlx->img[2], j, i);
			else if (mlx->game.map[i][j] == 'C')
				ft_put(mlx, mlx->img[4], j, i);
			if (mlx->game.x == j && mlx->game.y == i)
				draw_player(mlx, j, i);
			j++;
		}
		i++;
	}
}

void	draw_player(t_mlx *mlx, int x, int y)
{
	if (mlx->game.map[y][x] == 'E')
	{
		ft_put(mlx, mlx->img[3], x, y);
		if (!mlx->game.items)
			finish_the_mega_game(mlx);
	}
	else if (mlx->game.map[y][x] == 'C')
	{
		mlx->game.items -= 1;
		mlx->game.map[y][x] = '0';
		ft_put(mlx, mlx->img[3], x, y);
	}
	else if (mlx->game.map[y][x] == '0')
		ft_put(mlx, mlx->img[3], x, y);
	else if (mlx->game.map[y][x] == '1')
		ft_put(mlx->mlx, mlx->img[1], x, y);
}

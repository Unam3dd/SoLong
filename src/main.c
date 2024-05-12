/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:10:43 by stales            #+#    #+#             */
/*   Updated: 2022/05/13 19:50:51 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (ft_printf("usage : %s <map>\n", av[0]), 1);
	ft_memset(&mlx, 0, sizeof(mlx));
	if (parse_map(&mlx.game, av[1]))
		return (ft_strerr(&mlx.game), 1);
	so_long(&mlx);
	return (0);
}

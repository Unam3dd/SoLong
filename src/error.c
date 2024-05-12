/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:31:08 by stales            #+#    #+#             */
/*   Updated: 2022/05/13 10:48:51 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	ft_strerr(t_game *game)
{
	int	i;
	int	cn;

	i = 0;
	cn = 0;
	while (g_err_table[i].str && g_err_table[i].code != game->err)
		i++;
	while (g_err_table[i].cb[cn] && cn < 2)
		g_err_table[i].cb[cn++](game);
	if (g_err_table[i].code)
		ft_printf("Error\n%s", g_err_table[i].str);
}

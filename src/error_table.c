/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:59:22 by stales            #+#    #+#             */
/*   Updated: 2022/05/13 20:56:34 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stddef.h>

const t_error	g_err_table[] = {
	{{NULL, NULL}, ERR_FILE_EXT_MSG, ERR_FILE_EXT},
	{{NULL, NULL}, ERR_FILE_EMPTY_MSG, ERR_FILE_EMPTY},
	{{force_readline, free_map}, ERR_FILE_SIZEMAP_MSG, ERR_FILE_SIZEMAP},
	{{NULL, NULL}, ERR_FILE_NOTFOUND_MSG, ERR_FILE_NOTFOUND},
	{{force_readline, free_map}, ERR_FILE_MAPNOCOR_MSG, ERR_FILE_MAPNOCOR},
	{{free_map, NULL}, ERR_FILE_UNKNOWN_MSG, ERR_FILE_UNKNOWN},
	{{free_map, NULL}, ERR_FILE_BORDER_MSG, ERR_FILE_BORDER},
	{{free_map, NULL}, ERR_FILE_CTX_MSG, ERR_FILE_CTX},
	{{NULL, NULL}, NULL, 0}
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:20:58 by stales            #+#    #+#             */
/*   Updated: 2022/05/14 12:29:32 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//////////////////////////////////
//
//			DEFINES
//
//////////////////////////////////

# define ERR_FILE_EXT 3
# define ERR_FILE_EXT_MSG "Your filename extension is not *.ber !\n"
# define ERR_FILE_EMPTY 4
# define ERR_FILE_EMPTY_MSG "Your file is empty !\n"
# define ERR_FILE_SIZEMAP 5
# define ERR_FILE_SIZEMAP_MSG "Your map has not correct size !\n"
# define ERR_FILE_NOTFOUND 6
# define ERR_FILE_NOTFOUND_MSG "File not found !\n"
# define ERR_FILE_MAPNOCOR 7
# define ERR_FILE_MAPNOCOR_MSG "The format of your map is incorrect !\n"
# define ERR_FILE_UNKNOWN 9
# define ERR_FILE_UNKNOWN_MSG "Your map contains not mappable characters!\n"
# define ERR_FILE_BORDER 10
# define ERR_FILE_BORDER_MSG "Your map not contains border a certain place!\n"
# define ERR_FILE_CTX 11
# define ERR_FILE_CTX_MSG "Your map not contains required elements (01PCE) !\n"

//////////////////////////////////
//
//		TYPEDEFS & STRUCT
//
// 0: PLAYER, 1: COLLECTIBLE, 2: EXIT
//////////////////////////////////

typedef struct s_game
{
	char	*map[0xFFFF];
	int		flag[3];
	int		err;
	int		row;
	int		col;
	int		fd;
	int		x;
	int		y;
	int		items;
	int		move;
}	t_game;

typedef struct s_error
{
	void	(*cb[2])(t_game *game);
	char	*str;
	int		code;
}	t_error;

typedef struct s_mlx
{
	void	*img[5];
	void	*mlx;
	void	*win;
	t_game	game;
}	t_mlx;

//////////////////////////////////
//
//			ERROR TABLE
//
//////////////////////////////////

extern const t_error	g_err_table[];

//////////////////////////////////
//
//			ERROR
//
//////////////////////////////////

void	ft_strerr(t_game *game);

//////////////////////////////////
//
//			PARSER
//
//////////////////////////////////

int		check_filename(const char *f);
int		read_map(t_game *game);
int		parse_map(t_game *game, const char *filename);
int		check_map(t_game *game);
void	free_map(t_game *game);

//////////////////////////////////
//
//			UTILS
//
//////////////////////////////////

int		ft_strnchr(char *s, char c);
int		ft_readitems(char *s, char c);
void	ft_check_player(t_game *game, int line);
void	force_readline(t_game *game);
void	ft_put(t_mlx *mlx, void *img, int x, int y);

//////////////////////////////////
//
//			GRAPHICS
//
//////////////////////////////////

void	so_long(t_mlx *mlx);
void	init_images(t_mlx *mlx);
void	free_images(t_mlx *mlx);
void	draw_map(t_mlx *mlx);
void	draw_player(t_mlx *mlx, int x, int y);

//////////////////////////////////
//
//			CALLBACKS
//
//////////////////////////////////

int		hook_key(int k, t_mlx *mlx);
int		finish_the_mega_game(t_mlx *mlx);
void	move_player(t_mlx *mlx, int k);

#endif
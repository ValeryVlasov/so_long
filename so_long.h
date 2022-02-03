/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:58:42 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/13 14:28:25 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>//read, close, write
# include <fcntl.h>//open
# include <stdio.h>//printf, strerror, perror
# include <stdlib.h>//malloc, free, exit
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>

# define NO_EXIT "There are no exists on map!\n"
# define NO_PLAYER "There is no player on map!\n"
# define NO_COLLECT "There are no collects on map!\n"
# define MANY_PLAYERS "More than one players doesn't allowed!\n"
# define INVALID_SYM "Invalid symbols in map!\n"
# define NOT_RECTANGULAR "Map is not rectangular!\n"
# define INCOR_MAP "Map is incorrect!\n"
# define NOT_SURROUND "Map is not surrounded!\n"

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_gamedata
{
	int		**map;
	int		height;
	int		width;
	t_coord	player;
	t_coord	*exit;
	t_coord	*collect;
	int		cnt_collect;
	int		total_collect;
	int		cnt_exit;
	int		movecount;
}	t_gamedata;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_tex;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_tex		*player;
	t_tex		*exit;
	t_tex		*collect;
	t_tex		*walls;
	t_tex		*background;
	t_gamedata	*game;
	int			is_pressed;
}	t_game;

//map_handl.c
void	remove_collect(t_game *root, int x, int y);
void	change_position(t_game *root, int newX, int newY);

//move_player.c
int		move_up(t_game *root, t_gamedata *game);
int		move_down(t_game *root, t_gamedata *game);
int		move_left(t_game *root, t_gamedata *game);
int		move_right(t_game *root, t_gamedata *game);

//close_game.c
int		end_game(t_game *root, char *msg);

//event_handl.c
int		root_destroy(t_game *root);
int		key_press(int keycode, t_game *root);
int		key_release(int keycode, t_game *root);

//draw.c
void	draw_map(t_game *root);

//so_long.c
void	game_err(char *msg);

//game_init.c
t_game	*game_init(char *filename);

//gamedata_init.c
void	gamedata_init(t_game *root, char *filename);

//map_init.c
void	map_init(t_game *root, char *filename);

//map_read.c
void	map_read(t_game *root, char *line);

//check_map.c
void	check_map(t_game *root, char **map);

//check_map2.c
void	check_surrounded(t_game *root, char **map);
void	check_valid_sym(t_game *root, char **map);

#endif

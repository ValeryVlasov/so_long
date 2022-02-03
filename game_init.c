/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:56:35 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/13 14:35:04 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	textures_load(t_game *root, t_tex **img, char *path)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = (t_tex *)malloc(sizeof(t_tex));
	if (!(*img))
		end_game(root, "Error: can't malloc\n");
	(*img)->img = mlx_xpm_file_to_image(root->mlx,
			 path, &width, &height);
	if ((*img)->img == 0)
		end_game(root, "Error: can't load xpm file\n");
	(*img)->height = height;
	(*img)->width = width;
	(*img)->addr = mlx_get_data_addr((*img),
			&(*img)->bits_per_pixel,
			  &(*img)->line_length, &(*img)->endian);
}

static void	textures_init(t_game *root)
{
	textures_load(root, &root->player, "./img/player.xpm");
	textures_load(root, &root->collect, "./img/coin.xpm");
	textures_load(root, &root->walls, "./img/wall.xpm");
	textures_load(root, &root->exit, "./img/door.xpm");
	textures_load(root, &root->background, "./img/background.xpm");
}

static void	render_init(t_game *root)
{
	root->mlx = mlx_init();
	if (root->mlx == 0)
		end_game(root, "Error: mlx_init() failed\n");
	root->mlx_win = mlx_new_window(root->mlx,
			root->game->width * 32,
			   root->game->height * 32, "so_long");
}

t_game	*game_init(char *filename)
{
	t_game	*root;

	root = (t_game *)malloc(sizeof(t_game));
	if (!root)
		game_err("Malloc error!\n");
	root->mlx = NULL;
	root->mlx_win = NULL;
	root->player = NULL;
	root->exit = NULL;
	root->collect = NULL;
	root->walls = NULL;
	root->background = NULL;
	root->game = NULL;
	root->is_pressed = 0;
	gamedata_init(root, filename);
	render_init(root);
	textures_init(root);
	return (root);
}

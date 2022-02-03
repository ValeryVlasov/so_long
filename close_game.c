/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:50:24 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/13 14:36:29 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static void	clear_tex(t_game *root, t_tex *texture)
{
	if (texture->img != 0)
		mlx_destroy_image(root->mlx, texture->img);
	my_free(texture);
}

static void	clear_game(t_gamedata *game)
{
	int	i;

	i = -1;
	if (game != 0)
	{
		if (game->collect != 0)
			my_free(game->collect);
		if (game->exit != 0)
			my_free(game->exit);
		if (game->map != 0)
		{
			while (++i < game->height)
			{
				if (game->map[i] != 0)
					my_free(game->map[i]);
			}
			my_free(game->map);
		}
		my_free(game);
	}
}

int	end_game(t_game *root, char *msg)
{
	if (root != 0)
	{
		if (root->player != 0)
			clear_tex(root, root->player);
		if (root->collect != 0)
			clear_tex(root, root->collect);
		if (root->exit != 0)
			clear_tex(root, root->exit);
		if (root->walls != 0)
			clear_tex(root, root->walls);
		if (root->background != 0)
			clear_tex(root, root->background);
		clear_game(root->game);
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		my_free(root);
	}
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:59:04 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:59:13 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gamedata_init(t_game *root, char *filename)
{
	root->game = (t_gamedata *)malloc(sizeof(t_gamedata));
	if (!root->game)
		end_game(root, "Malloc error\n");
	root->game->map = NULL;
	root->game->height = 0;
	root->game->width = 0;
	root->game->player.x = 0;
	root->game->player.y = 0;
	root->game->exit = NULL;
	root->game->collect = NULL;
	root->game->cnt_collect = 0;
	root->game->cnt_exit = 0;
	root->game->movecount = 0;
	map_init(root, filename);
}

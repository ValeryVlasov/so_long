/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:52:48 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:53:17 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_collect(t_game *root, int x, int y)
{
	int	i;

	i = -1;
	while (++i < root->game->total_collect)
	{
		if (root->game->collect[i].x == x && root->game->collect[i].y == y)
		{
			root->game->collect[i].x = -1;
			root->game->collect[i].y = -1;
			root->game->cnt_collect--;
			root->game->map[y][x] = 0;
			break ;
		}
	}
}

void	change_position(t_game *root, int newX, int newY)
{
	root->game->map[root->game->player.y][root->game->player.x] = 0;
	root->game->map[newY][newX] = (int)('P' - '0');
}

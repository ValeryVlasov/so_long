/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:52:01 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:52:30 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tex_to_window(t_game *root, void *img, int x, int y)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win, img, x * 32, y * 32);
}

void	draw_map(t_game *root)
{
	int	i;
	int	j;

	i = -1;
	while (++i < root->game->height)
	{
		j = -1;
		while (++j < root->game->width)
		{
			put_tex_to_window(root, root->background->img, j, i);
			if (root->game->map[i][j] == 1)
				put_tex_to_window(root, root->walls->img, j, i);
			else if (root->game->map[i][j] == (int)('C' - '0'))
				put_tex_to_window(root, root->collect->img, j, i);
			else if (root->game->map[i][j] == (int)('E' - '0'))
				put_tex_to_window(root, root->exit->img, j, i);
			else if (root->game->map[i][j] == (int)('P' - '0'))
				put_tex_to_window(root, root->player->img, j, i);
		}
	}
}

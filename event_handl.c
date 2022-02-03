/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:01:04 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 19:01:23 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	root_destroy(t_game *root)
{
	(void)root;
	exit(0);
}

int	key_press(int keycode, t_game *root)
{
	int	moved;

	moved = 0;
	if (root->is_pressed)
		return (0);
	root->is_pressed = 1;
	if (keycode == KEY_UP || keycode == KEY_W)
		moved = move_up(root, root->game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		moved = move_down(root, root->game);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		moved = move_left(root, root->game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		moved = move_right(root, root->game);
	else if (keycode == KEY_ESC)
		end_game(root, NULL);
	else
		return (0);
	if (moved)
		root->game->movecount++;
	else
		return (0);
	printf("Current movecount is %d\n", root->game->movecount);
	return (0);
}

int	key_release(int keycode, t_game *root)
{
	(void)keycode;
	root->is_pressed = 0;
	mlx_clear_window(root->mlx, root->mlx_win);
	draw_map(root);
	return (0);
}

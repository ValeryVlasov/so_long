/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:56:15 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:56:18 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *root, t_gamedata *game)
{
	if ('1' == (char)game->map[game->player.y - 1][game->player.x] + '0')
		return (0);
	else if ('C' == (char)game->map[game->player.y - 1][game->player.x] + '0')
	{
		remove_collect(root, game->player.x, game->player.y - 1);
		change_position(root, game->player.x, game->player.y - 1);
		game->player.y--;
	}
	else if ('E' == (char)game->map[game->player.y - 1][game->player.x] + '0')
	{
		if (game->cnt_collect > 0)
			return (0);
		change_position(root, game->player.x, game->player.y - 1);
		game->player.y--;
		printf("Congratulations! You've finished the game!\n");
		printf("Total count of moves is %d\n", ++game->movecount);
		end_game(root, NULL);
		exit(0);
	}
	else
	{
		change_position(root, game->player.x, game->player.y - 1);
		game->player.y--;
	}
	return (1);
}

int	move_down(t_game *root, t_gamedata *game)
{
	if ('1' == (char)game->map[game->player.y + 1][game->player.x] + '0')
		return (0);
	else if ('C' == (char)game->map[game->player.y + 1][game->player.x] + '0')
	{
		remove_collect(root, game->player.x, game->player.y + 1);
		change_position(root, game->player.x, game->player.y + 1);
		game->player.y++;
	}
	else if ('E' == (char)game->map[game->player.y + 1][game->player.x] + '0')
	{
		if (game->cnt_collect > 0)
			return (0);
		change_position(root, game->player.x, game->player.y + 1);
		game->player.y++;
		printf("Congratulations! You've finished the game!\n");
		printf("Total count of moves is %d\n", ++game->movecount);
		end_game(root, NULL);
		exit(0);
	}
	else
	{
		change_position(root, game->player.x, game->player.y + 1);
		game->player.y++;
	}
	return (1);
}

int	move_right(t_game *root, t_gamedata *game)
{
	if ('1' == (char)game->map[game->player.y][game->player.x + 1] + '0')
		return (0);
	else if ('C' == (char)game->map[game->player.y][game->player.x + 1] + '0')
	{
		remove_collect(root, game->player.x + 1, game->player.y);
		change_position(root, game->player.x + 1, game->player.y);
		game->player.x++;
	}
	else if ('E' == (char)game->map[game->player.y][game->player.x + 1] + '0')
	{
		if (game->cnt_collect > 0)
			return (0);
		change_position(root, game->player.x + 1, game->player.y);
		game->player.x++;
		printf("Congratulations! You've finished the game!\n");
		printf("Total count of moves is %d\n", ++game->movecount);
		end_game(root, NULL);
		exit(0);
	}
	else
	{
		change_position(root, game->player.x + 1, game->player.y);
		game->player.x++;
	}
	return (1);
}

int	move_left(t_game *root, t_gamedata *game)
{
	if ('1' == (char)game->map[game->player.y][game->player.x - 1] + '0')
		return (0);
	else if ('C' == (char)game->map[game->player.y][game->player.x - 1] + '0')
	{
		remove_collect(root, game->player.x - 1, game->player.y);
		change_position(root, game->player.x - 1, game->player.y);
		game->player.x--;
	}
	else if ('E' == (char)game->map[game->player.y][game->player.x - 1] + '0')
	{
		if (game->cnt_collect > 0)
			return (0);
		change_position(root, game->player.x - 1, game->player.y);
		game->player.x--;
		printf("Congratulations! You've finished the game!\n");
		printf("Total count of moves is %d\n", ++game->movecount);
		end_game(root, NULL);
		exit(0);
	}
	else
	{
		change_position(root, game->player.x - 1, game->player.y);
		game->player.x--;
	}
	return (1);
}

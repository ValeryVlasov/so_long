/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:41:38 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/10 13:21:17 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_exit(t_game *root, char **map)
{
	int	exit_obj;
	int	i;
	int	j;

	i = -1;
	exit_obj = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				exit_obj++;
		}
	}
	if (exit_obj == 0)
		end_game(root, NO_EXIT);
	root->game->cnt_exit = exit_obj;
}

static void	check_rectangle(t_game *root, char **map)
{
	int	i;
	int	prev;
	int	cur;

	i = -1;
	while (map[++i])
	{
		if (i == 0)
			prev = ft_strlen(map[0]);
		else
		{
			cur = ft_strlen(map[i]);
			if (cur != prev)
				end_game(root, NOT_RECTANGULAR);
			prev = cur;
		}
	}
	root->game->width = ft_strlen(map[0]);
	root->game->height = i;
}

static void	check_collect(t_game *root, char **map)
{
	int	collect;
	int	i;
	int	j;

	collect = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				collect++;
		}
	}
	if (collect == 0)
		end_game(root, NO_COLLECT);
	root->game->cnt_collect = collect;
	root->game->total_collect = collect;
}

static void	check_player(t_game *root, char **map)
{
	int	player;
	int	i;
	int	j;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && player != 0)
				end_game(root, MANY_PLAYERS);
			if (map[i][j] == 'P')
			{
				player++;
				root->game->player.x = j;
				root->game->player.y = i;
			}
		}
	}
	if (player == 0)
		end_game(root, NO_PLAYER);
}

void	check_map(t_game *root, char **map)
{
	check_rectangle(root, map);
	check_valid_sym(root, map);
	check_surrounded(root, map);
	check_exit(root, map);
	check_player(root, map);
	check_collect(root, map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:54:17 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/13 14:11:49 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int		i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
		free(map[i]);
	free(map);
}

static void	get_coord(t_game *root, char **map, t_coord coord, int *obj_c)
{
	if (map[coord.y][coord.x] == 'P')
	{
		root->game->player.x = coord.x;
		root->game->player.y = coord.y;
	}
	else if (map[coord.y][coord.x] == 'C')
	{
		root->game->collect[*obj_c].x = coord.x;
		root->game->collect[*obj_c].y = coord.y;
		(*obj_c)++;
	}
}

static void	get_coord_ex(t_game *root, char **map, t_coord coord, int *obj_e)
{
	if (map[coord.y][coord.x] == 'E')
	{
		root->game->exit[*obj_e].x = coord.x;
		root->game->exit[*obj_e].y = coord.y;
		(*obj_e)++;
	}
}

static void	map_parse(t_game *root, char **map)
{
	int		i;
	int		j;
	int		obj_c;
	int		obj_e;
	t_coord	crd;

	i = -1;
	obj_c = 0;
	obj_e = 0;
	while (map[++i])
	{
		root->game->map[i] = (int *)malloc(sizeof(int) * root->game->width);
		if (!root->game->map[i])
			end_game(root, "Malloc error\n");
		j = -1;
		while (map[i][++j])
		{
			crd.x = j;
			crd.y = i;
			get_coord(root, map, crd, &obj_c);
			get_coord_ex(root, map, crd, &obj_e);
			root->game->map[i][j] = map[i][j] - '0';
		}
	}
}

void	map_read(t_game *root, char *line)
{
	char	**map;

	map = ft_split(line, '\n');
	free(line);
	check_map(root, map);
	root->game->exit = malloc(sizeof(t_coord) * root->game->cnt_exit);
	if (!root->game->exit)
		end_game(root, "Malloc error\n");
	root->game->collect = malloc(sizeof(t_coord) * root->game->cnt_collect);
	if (!root->game->collect)
		end_game(root, "Malloc error\n");
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (!root->game->map)
		end_game(root, "Malloc error\n");
	map_parse(root, map);
	free_map(map);
}

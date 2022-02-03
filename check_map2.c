/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:45:36 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:45:50 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_columns(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static int	check_strings(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_surrounded(t_game *root, char **map)
{
	int	i;
	int	j;
	int	col;
	int	str;

	i = -1;
	col = check_columns(map);
	str = check_strings(map);
	if (str <= 2 || col <= 2)
		end_game(root, NOT_SURROUND);
	while (++i < str)
	{
		if (i == 0 || i == str - 1)
		{
			j = -1;
			while (map[i][++j])
			{
				if (map[i][j] != '1')
					end_game(root, NOT_SURROUND);
			}
		}
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			end_game(root, NOT_SURROUND);
	}
}

static int	is_map_obj(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
	    && map[i][j] != 'P' && map[i][j] != 'E')
		return (1);
	return (0);
}

void	check_valid_sym(t_game *root, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_map_obj(map, i, j))
			{
				if (map[i][j] != '\n')
					end_game(root, INVALID_SYM);
				else if (is_map_obj(map, i, j + 1))
					end_game(root, INCOR_MAP);
			}
		}
	}
}

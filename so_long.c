/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:01:39 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 19:01:57 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void	check_map_name(char *name)
{
	char	*temp;
	int		len;

	len = ft_strlen(name);
	if (len <= 4 || name[len - 4] != '.')
		game_err("Incorrect map name!\n");
	temp = ft_strrchr(name, '.');
	if (ft_strncmp(temp, ".ber", ft_strlen(temp)) != 0)
		game_err("Incorrect extension of file!\n");
}

int	main(int argc, char **argv)
{
	t_game	*root;

	if (argc != 2)
		game_err("Error: wrong number of parameters\n");
	check_map_name(argv[1]);
	root = game_init(argv[1]);
	draw_map(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, root_destroy, root);
	mlx_loop(root->mlx);
	return (0);
}

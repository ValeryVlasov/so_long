/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:53:31 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/09 18:53:51 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_file(t_game *root, int fd, char **file, char buf[])
{
	char	*temp;

	temp = ft_strjoin(*file, buf);
	free(*file);
	*file = temp;
	if (!*file)
	{
		close(fd);
		end_game(root, "Error: ft_strjoin() failed\n");
	}
}

static void	file_read(t_game *root, int fd, char **file)
{
	char	buffer[1024 + 1];
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, 32);
		if (i == -1)
		{
			close(fd);
			free(*file);
			end_game(root, "Error: read failed\n");
		}
		else
		{
			buffer[i] = 0;
			parse_file(root, fd, file, buffer);
		}
	}
}

static char	*file_init(t_game *root, int fd)
{
	char	*file;

	file = ft_calloc(1, 1);
	if (!file)
	{
		close(fd);
		end_game(root, "Error: ft_calloc() failed\n");
	}
	return (file);
}

void	map_init(t_game *root, char *filename)
{
	int		fd;
	char	*file_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		end_game(root, "Error! File doesn't exist!\n");
	file_line = file_init(root, fd);
	file_read(root, fd, &file_line);
	close(fd);
	map_read(root, file_line);
}

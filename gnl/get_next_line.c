/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:35:52 by tgrounds          #+#    #+#             */
/*   Updated: 2021/11/13 14:36:09 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

static char	*to_out(char *s)
{
	char	*str_out;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str_out = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_out)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str_out[i] = s[i];
		i++;
	}
	str_out[i] = '\0';
	return (str_out);
}

static char	*resave(char *to_save)
{
	char	*issave;
	size_t	i;
	size_t	j;

	if (!to_save)
		return (0);
	j = 0;
	i = 0;
	while (to_save[i] && to_save[i] != '\n')
		i++;
	if (!to_save[i])
	{
		free(to_save);
		return (0);
	}
	issave = (char *)malloc(sizeof(char) * ((ft_strlen(to_save) - i) + 1));
	if (!issave)
		return (0);
	i++;
	while (to_save[i])
		issave[j++] = to_save[i++];
	issave[j] = '\0';
	free(to_save);
	return (issave);
}

int	free_buff(int reader, char *buff)
{
	if (reader != -1)
		return (1);
	free(buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*cur_str;
	char		*buffer;
	int			reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	reader = 1;
	while (!newline_ret(cur_str) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (!free_buff(reader, buffer))
			return (-1);
		buffer[reader] = '\0';
		cur_str = ft_strjoin(cur_str, buffer);
	}
	free(buffer);
	*line = to_out(cur_str);
	cur_str = resave(cur_str);
	if (reader == 0)
		return (0);
	return (1);
}

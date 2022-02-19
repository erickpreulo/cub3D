/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:51:53 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 12:52:53 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_fd(char *filepath, char *filename)
{
	char	*path;
	int 	fd;

	path = ft_strjoin(filepath, filename);
	if (!path)
		exit_error("Malloc failed on creating path");
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		exit_error("Couldn't open the .cub file");
	return fd;
}

void	init_file()
{
	t_cub3d		*cub3d;
	char		*ext;
	int			fd;
	int			ret;
	char		*line;

	cub3d =  get_cub3d();
	ext = ft_strrchr(cub3d->config.file, '.');
	cub3d->config.textures[NO] = NULL;
	cub3d->config.textures[SO] = NULL;
	cub3d->config.textures[WE] = NULL;
	cub3d->config.textures[EA] = NULL;
	if (!ext || ft_strcmp(ext, ".cub"))
		exit_error("File must have .cub extension!");
	fd = open_fd("maps/", cub3d->config.file);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(&line, fd);
		parse_settings(line);
		free(line);
	}
	close(fd);
}
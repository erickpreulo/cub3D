/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:51:53 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 11:27:43 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_file()
{
	t_cub3d		*cub3d;
	char		*ext;
	int			fd;
	int			ret;
	char		*line;

	cub3d =  get_cub3d();
	ext = ft_strrchr(cub3d->config.file, '.');
	if (!ext || ft_strcmp(ext, ".cub"))
		exit_error("File must have .cub extension!");
	fd = open(cub3d->config.file, O_RDONLY);
	if (fd == -1)
		exit_error("Couldn't open the .cub file");
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(&line, fd);
		parse_settings(line);
		free(line);
	}
	close(fd);
}
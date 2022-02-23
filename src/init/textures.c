/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:36:43 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 14:07:01 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_logo(void)
{
	t_cub3d	*cub3d;
	t_texture	*t;

	cub3d = get_cub3d();
	t = &cub3d->config.logo;
	t->img.img = mlx_xpm_file_to_image(cub3d->mlx, "./src/assets/logo-42.xpm",
										&t->width, &t->height);
	if (!t->img.img)
		exit_error("Import logo-42.xpm to image failed");
	t->img.addr = mlx_get_data_addr(t->img.img, &t->img.bpp,
								&t->img.line_length, &t->img.endian);
	if (!t->img.addr)
		exit_error("Get logo-42.xpm data pointer failed");
}

void	validation_textures(void)
{
	t_cub3d		*cub3d;
	t_texture	*t;
	int 		dir;

	cub3d = get_cub3d();
	dir = -1;
	while (++dir < 4)
	{
		t = &cub3d->config.textures[dir];
		t->img.img = mlx_xpm_file_to_image(cub3d->mlx, t->path,
										&t->width, &t->height);
		if (!t->img.img)
			exit_error("Import .xpm to image failed");
		t->img.addr = mlx_get_data_addr(t->img.img, &t->img.bpp,
								&t->img.line_length, &t->img.endian);
		if (!t->img.addr)
			exit_error("Get .xpm data pointer failed");
	}
	load_logo();
}
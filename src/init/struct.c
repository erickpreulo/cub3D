/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:28:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 13:27:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*get_cub3d(void)
{
	static t_cub3d	*cub3d;

	if (!cub3d)
		cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		exit(0);
	return (cub3d);
}

void	init_struct(void)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	cub3d->img.img = NULL;
	cub3d->mlx = NULL;
	cub3d->config.textures[NO].img.img = NULL;
	cub3d->config.textures[NO].path = NULL;
	cub3d->config.textures[SO].img.img = NULL;
	cub3d->config.textures[SO].path = NULL;
	cub3d->config.textures[WE].img.img = NULL;
	cub3d->config.textures[WE].path = NULL;
	cub3d->config.textures[EA].img.img = NULL;
	cub3d->config.textures[EA].path = NULL;
	cub3d->config.logo.img.img = NULL;
	cub3d->config.floor = -1;
	cub3d->config.ceilling = -1;
	cub3d->config.map.map = NULL;
	cub3d->config.hud.minimap = true;
	cub3d->config.hud.ray = false;
	cub3d->config.hud.logo = true;
}

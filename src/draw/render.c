/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:15:55 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 11:22:37 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(void)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	draw_ceilling();
	draw_floor();
	draw_walls();
	draw_minimap();
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->config.logo.img.img,
									WINDOW_WIDTH - cub3d->config.logo.width,
									WINDOW_HEIGHT - cub3d->config.logo.height);

	// TEMPORARY! TEXTURES AT LEFT BOTTOM
	for (int i = 0; i < 4; i++)
	{
		mlx_put_image_to_window(cub3d->mlx, cub3d->win,
			cub3d->config.textures[i].img.img,
			i * 32,
			WINDOW_HEIGHT - 32);
	}
}

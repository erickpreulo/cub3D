/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:19:14 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 09:32:16 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceilling()
{
	t_cub3d	*cub3d;

	int x;
	int y;

	x = -1;
	cub3d = get_cub3d();
	while(++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y <= WINDOW_HEIGHT / 2)
			my_mlx_pixel_put(&cub3d->img, x, y, cub3d->config.ceilling);
	}
}

void	draw_floor()
{
	t_cub3d	*cub3d;

	int x;
	int y;

	x = -1;
	y = -1;
	cub3d = get_cub3d();
	while(++x < WINDOW_WIDTH)
	{
		y = WINDOW_HEIGHT / 2;
		while (++y < WINDOW_HEIGHT)
			my_mlx_pixel_put(&cub3d->img, x, y, cub3d->config.floor);
	}
}
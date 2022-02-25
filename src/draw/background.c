/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:19:14 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 00:02:00 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_background(t_position start, int width, int height, int color)
{
	t_cub3d	*cub3d;
	int		x;
	int		y;

	cub3d = get_cub3d();
	x = start.x;
	while (x < start.x + width)
	{
		y = start.y;
		while (y < start.y + height)
		{
			my_mlx_pixel_put(&cub3d->img, x, y, apply_shadow_background(color, y));
			y++;
		}
		x++;
	}
}

void	draw_ceilling(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = 0;
	draw_square_background(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.ceilling);
}

void	draw_floor(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = WINDOW_HEIGHT / 2;
	draw_square_background(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.floor);
}

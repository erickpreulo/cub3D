/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:03:36 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 15:31:11 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_position start, int width, int height, int color)
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
			my_mlx_pixel_put(&cub3d->img, x, y, color);
			y++;
		}
		x++;
	}
}

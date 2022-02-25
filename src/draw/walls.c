/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:40:26 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 10:09:46 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_w(int i)
{
	t_cub3d		*cub3d;
	t_direction	dir;

	cub3d = get_cub3d();
	dir = cub3d->rays[i].pos.direction;
	if (dir == NO)
		return (cub3d->rays[i].pos.x - floor(cub3d->rays[i].pos.x));
	if (dir == SO)
		return (ceil(cub3d->rays[i].pos.x) - cub3d->rays[i].pos.x);
	if (dir == WE)
		return (ceil(cub3d->rays[i].pos.y) - cub3d->rays[i].pos.y);
	if (dir == EA)
		return (cub3d->rays[i].pos.y - floor(cub3d->rays[i].pos.y));
	return (0);
}

int	get_texture_color(t_texture *t, double h, double w, double dist)
{
	int	*addr;
	int	color;

	addr = (int *)t->img.addr;
	color = addr[t->height * ((int)(h * t->height)) + (int)(w * t->width)];
	return (apply_shadow(color, dist));
}

void	draw_line_wall(int i, double dist, t_cub3d *cub3d)
{
	int				j;
	double			h;
	t_texture		*t;
	const int		size = (WINDOW_HEIGHT / 2) / dist;
	const double	w = get_w(i);

	j = (WINDOW_HEIGHT / 2) - size;
	t = &cub3d->config.textures[cub3d->rays[i].pos.direction];
	while (++j < (WINDOW_HEIGHT / 2) + size)
	{
		if (j < 0 || j > WINDOW_HEIGHT - 1)
			continue ;
		h = ((double)j - ((WINDOW_HEIGHT - (2 * size)) / 2))
			/ (double)(2 * size);
		my_mlx_pixel_put(&cub3d->img, i, j, get_texture_color(t, h, w, dist));
	}
}

void	draw_walls(void)
{
	t_cub3d	*cub3d;
	int		i;

	cub3d = get_cub3d();
	i = -1;
	while (++i < WINDOW_WIDTH)
		draw_line_wall(i, cub3d->rays[i].dist, cub3d);
}

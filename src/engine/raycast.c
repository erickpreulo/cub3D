/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 23:53:51 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_dist(t_position pos1, t_position pos2)
{
	double	dist;

	dist = (pos1.x - pos2.x) * (pos1.x - pos2.x);
	dist += (pos1.y - pos2.y) * (pos1.y - pos2.y);

	return (sqrt(dist));
}

t_position get_ray_vertical(t_cub3d *cub3d)
{
	t_position	pos;
	double		b;

	if (cub3d->player.pos.angle > 0 && cub3d -> player.pos.angle < PI)
		pos.y =  floor(cub3d->player.pos.y);
	else
		pos.y = ceill(cub3d->player.pos.y);
	b = 1/tan(cub3d->player.pos.angle) * (cub3d->player.pos.y - pos.y);
	pos.x = cub3d->player.pos.x + b;
	return (pos);
}

t_position get_ray_horizontal(t_cub3d *cub3d)
{
	t_position	pos;
	double		b;

	if (cub3d->player.pos.angle > PI / 2 && cub3d->player.pos.angle < 3 * PI / 2)
		pos.x = floor(cub3d->player.pos.x);
	else
		pos.x = ceill(cub3d->player.pos.x);
	b = tan(cub3d->player.pos.angle) * (cub3d->player.pos.x - pos.x);
	pos.y = cub3d->player.pos.y + b;
	return (pos);
}

void	update_raycast(void)
{
	t_cub3d		*cub3d;
	t_position	pos_h;
	t_position	pos_v;

	cub3d = get_cub3d();
	pos_h = get_ray_horizontal(cub3d);
	pos_v = get_ray_vertical(cub3d);

	if (calc_dist(pos_h, cub3d->player.pos) < calc_dist(pos_v, cub3d->player.pos))
		cub3d->ray.pos = pos_h;
	else
		cub3d->ray.pos = pos_v;
}

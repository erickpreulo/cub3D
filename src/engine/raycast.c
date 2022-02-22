/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/22 12:03:35 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_position get_ray_horizontal(t_cub3d *cub3d)
{
	t_position	ray;
	t_position	incr;
	double		a_tan;

	ray.angle = cub3d->player.pos.angle;
	a_tan = -1/tan(ray.angle);
	if (ray.angle == 0 || ray.angle == PI)
		return (limit_position());
	if (ray.angle > PI) // LOOKING DOWN
	{
		ray.y = floor(cub3d->player.pos.y);
		ray.x = (cub3d->player.pos.y - ray.y) * a_tan + cub3d->player.pos.x;
		incr.y = 1;
		incr.x = incr.y * a_tan;
	}
	else // LOOKING UP
	{
		ray.y = floor(cub3d->player.pos.y) + 1 - 0.0001;
		ray.x = (cub3d->player.pos.y - ray.y) * a_tan + cub3d->player.pos.x;
		incr.y = -1;
		incr.x = incr.y * a_tan;
	}
	while (1)
	{
		if (ray.y - 1 < 0 || ray.y - 1 >= cub3d->config.map.height - 1)
			break;
		if (ray.x < 0 || ray.x >= cub3d->config.map.width - 1)
			break;
		if (cub3d->config.map.map[(int)ray.y][(int)ray.x] == '1')
			break;
		ray.x += incr.x;
		ray.y += incr.y;
	}
	return (ray);
}

t_position get_ray_vertical(t_cub3d *cub3d)
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

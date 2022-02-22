/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/22 20:59:23 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_obstacle(t_cub3d *cub3d, t_position *ray, t_position *incr)
{
	while (1)
	{
		if (ray->y <= 0 || ray->y >= cub3d->config.map.height - 1)
			break;
		if (ray->x <= 0 || ray->x >= cub3d->config.map.width - 1)
			break;
		if (cub3d->config.map.map[(int)ray->y][(int)ray->x] == '1')
			break;
		ray->x += incr->x;
		ray->y += incr->y;
	}
}

t_position get_ray_horizontal(t_cub3d *cub3d)
{
	t_position	ray;
	t_position	incr;
	double		a_tan;

	ray.angle = cub3d->player.pos.angle;
	a_tan = -1/tan(ray.angle);
	if (ray.angle == 0 || ray.angle == PI)
		return (limit_position());
	ray.y = ceil(cub3d->player.pos.y);
	incr.y = 1;
	if (ray.angle < PI)
	{
		ray.y = floor(cub3d->player.pos.y) - 0.0001;
		incr.y = -1;
	}
	ray.x = (cub3d->player.pos.y - ray.y) * -a_tan + cub3d->player.pos.x;
	incr.x = incr.y * a_tan;
	find_obstacle(cub3d, &ray, &incr);
	return (ray);
	
}

t_position get_ray_vertical(t_cub3d *cub3d)
{
	t_position	ray;
	t_position	incr;
	double		n_tan;

	ray.angle = cub3d->player.pos.angle;
	n_tan = -tan(ray.angle);
	if (ray.angle == PI / 2 || ray.angle == PI + (PI / 2))
		return (limit_position());
	ray.x = ceil(cub3d->player.pos.x);
	incr.x = 1;
	if (ray.angle > PI / 2 && ray.angle < PI + (PI / 2))
	{
		ray.x = floor(cub3d->player.pos.x) - 0.0001;
		incr.x = -1;
	}
	ray.y = (cub3d->player.pos.x - ray.x) * -n_tan + cub3d->player.pos.y;
	incr.y = incr.x * n_tan;
	find_obstacle(cub3d, &ray, &incr);
	return (ray);
}

void	update_raycast(void)
{
	t_cub3d		*cub3d;
	t_position	pos_h;
	t_position	pos_v;

	cub3d = get_cub3d();
	pos_h = get_ray_horizontal(cub3d);
	pos_v = get_ray_vertical(cub3d);

	if (calc_dist(pos_h, cub3d->player.pos) <= calc_dist(pos_v, cub3d->player.pos))
		cub3d->ray.pos = pos_h;
	else
		cub3d->ray.pos = pos_v;
}

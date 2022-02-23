/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 00:20:09 by egomes           ###   ########.fr       */
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

t_position get_ray_horizontal(t_cub3d *cub3d, double angle)
{
	t_position	ray;
	t_position	incr;
	double		a_tan;

	ray.angle = angle;
	a_tan = -1/tan(ray.angle);
	if (ray.angle == 0 || ray.angle == PI)
		return (limit_position());
	ray.y = ceil(cub3d->player.pos.y);
	incr.y = 1;
	ray.texture = SO;
	if (ray.angle < PI)
	{
		ray.y = floor(cub3d->player.pos.y) - 0.0001;
		incr.y = -1;
		ray.texture = NO;
	}
	ray.x = (cub3d->player.pos.y - ray.y) * -a_tan + cub3d->player.pos.x;
	incr.x = incr.y * a_tan;
	find_obstacle(cub3d, &ray, &incr);
	return (ray);
	
}

t_position get_ray_vertical(t_cub3d *cub3d, double angle)
{
	t_position	ray;
	t_position	incr;
	double		n_tan;

	ray.angle = angle;
	n_tan = -tan(ray.angle);
	if (ray.angle == PI / 2 || ray.angle == PI + (PI / 2))
		return (limit_position());
	ray.x = ceil(cub3d->player.pos.x);
	incr.x = 1;
	ray.texture = EA;
	if (ray.angle > PI / 2 && ray.angle < PI + (PI / 2))
	{
		ray.x = floor(cub3d->player.pos.x) - 0.0001;
		incr.x = -1;
		ray.texture = WE;
	}
	ray.y = (cub3d->player.pos.x - ray.x) * -n_tan + cub3d->player.pos.y;
	incr.y = incr.x * n_tan;
	find_obstacle(cub3d, &ray, &incr);
	return (ray);
}

double	get_piece_of_angle(int i, t_cub3d *cub3d)
{
	double	dr; 
	double	angle;

	dr = cub3d->config.fov / WINDOW_WIDTH;
	angle = cub3d->player.pos.angle + cub3d->config.fov / 2;
	angle -= dr * (double)i;
	return (correct_angle(angle));
}

void	update_raycast(void)
{
	t_cub3d		*cub3d;
	t_position	pos_h;
	t_position	pos_v;
	int			i;
	double		angle;
	double		ca;

	cub3d = get_cub3d();
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		angle = get_piece_of_angle(i, cub3d);
		pos_h = get_ray_horizontal(cub3d, angle);
		pos_v = get_ray_vertical(cub3d, angle);
		if (calc_dist(pos_h, cub3d->player.pos) <= calc_dist(pos_v, cub3d->player.pos))
		{
			cub3d->ray[i].pos = pos_h;
			cub3d->ray[i].dist = calc_dist(pos_h, cub3d->player.pos);
		}
		else
		{
			cub3d->ray[i].pos = pos_v;
			cub3d->ray[i].dist = calc_dist(pos_v, cub3d->player.pos);
		}
		ca = correct_angle(cub3d->player.pos.angle - cub3d->ray[i].pos.angle);
		cub3d->ray[i].dist *= cos(ca);
	}
}

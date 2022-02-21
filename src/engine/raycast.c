/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 19:54:14 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_position get_ray_vertical(t_cub3d *cub3d)
{
	t_position	pos;
	double b;

	if (cub3d->player.pos.angle > 0 && cub3d -> player.pos.angle < PI)
		pos.y = 0;
	else
		pos.y = cub3d->config.map.height + 1;

	b = 1/tan(cub3d->player.pos.angle) * fabs(pos.y - cub3d->player.pos.y);
	pos.x = cub3d->player.pos.x + b;

	return (pos);
}

t_position get_ray_horizontal(t_cub3d *cub3d)
{
	t_position	pos;

	if (cub3d->player.pos.angle > PI / 2 && cub3d->player.pos.angle < 3 * PI / 2)
		pos.x = 0;
	else
		pos.x = cub3d->config.map.width + 1;

	

	return (pos);
}

void	update_raycast(void)
{
	t_cub3d		*cub3d;

	cub3d = get_cub3d();
	cub3d->ray.pos = get_ray_vertical(cub3d);

	
}

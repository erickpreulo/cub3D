/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:47:44 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/22 19:36:54 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_position	fix_boundaries(t_position pos)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	if (pos.x < 1)
		pos.x = 1;
	if (pos.x > cub3d->config.map.width - 1)
		pos.x = cub3d->config.map.width - 1;
	if (pos.y < 1)
		pos.y = 1;
	if (pos.y > cub3d->config.map.height - 1)
		pos.y = cub3d->config.map.height - 1;
	pos.angle = correct_angle(pos.angle);
	return (pos);
}

t_position	new_position(void)
{
	t_position	pos;

	pos.x = 0;
	pos.y = 0;
	pos.angle = 0;
	return (pos);
}

t_position	limit_position(void)
{
	t_position	pos;

	pos.x = DBL_MAX;
	pos.y = DBL_MAX;
	pos.angle = 2 * PI;
	return (pos);
}

double		calc_dist(t_position pos1, t_position pos2)
{
	double	dist;

	dist = (pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y);
	return (sqrt(dist));
}
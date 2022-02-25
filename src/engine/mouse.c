/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:33:47 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/25 10:08:04 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hook_mousemove(int x, int y, t_cub3d *cub3d)
{
	int		diff;

	(void) y;
	diff = cub3d->config.last_x - x;
	cub3d->config.last_x = x;
	cub3d->player.pos.angle = correct_angle
		(cub3d->player.pos.angle + diff * 0.005);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:19:14 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 10:06:23 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceilling()
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = 0;
	draw_square(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.ceilling);

}

void	draw_floor()
{
	t_cub3d	*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = WINDOW_HEIGHT / 2;
	draw_square(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.floor);
}
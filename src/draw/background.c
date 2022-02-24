/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:19:14 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 13:07:06 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceilling(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = 0;
	draw_square(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.ceilling);
}

void	draw_floor(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = 0;
	pos.y = WINDOW_HEIGHT / 2;
	draw_square(pos, WINDOW_WIDTH, WINDOW_HEIGHT / 2, cub3d->config.floor);
}

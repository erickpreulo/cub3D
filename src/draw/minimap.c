/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:38:37 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 14:44:34 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_aim(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = cub3d->player.pos.x + cos(cub3d->player.pos.angle);
	pos.y = cub3d->player.pos.y - sin(cub3d->player.pos.angle);
	pos.x = MINIMAP_OFFSET + pos.x * MINIMAP_RATIO;
	pos.y = MINIMAP_OFFSET + pos.y * MINIMAP_RATIO;
	pos.x--;
	pos.y--;
	draw_square(pos, 3, 3, C_RED);
}

void	draw_player(void)
{
	t_cub3d		*cub3d;
	t_position	pos;

	cub3d = get_cub3d();
	pos.x = MINIMAP_OFFSET + cub3d->player.pos.x * MINIMAP_RATIO;
	pos.y = MINIMAP_OFFSET + cub3d->player.pos.y * MINIMAP_RATIO;
	pos.x -= 2;
	pos.y -= 2;
	draw_square(pos, PLAYER_SIZE, PLAYER_SIZE, C_RED);
	draw_aim();
}

void	draw_minimap_square(int i, int j)
{
	t_cub3d		*cub3d;
	t_position	pos;
	char		c;

	cub3d = get_cub3d();
	c = cub3d->config.map.map[i][j];
	pos.x = MINIMAP_OFFSET + j * MINIMAP_RATIO;
	pos.y = MINIMAP_OFFSET + i * MINIMAP_RATIO;
	if (c == ' ')
		draw_square(pos, MINIMAP_RATIO, MINIMAP_RATIO, C_GRAY);
	else if (c == '1')
		draw_square(pos, MINIMAP_RATIO, MINIMAP_RATIO, C_BLACK);	
	else
		draw_square(pos, MINIMAP_RATIO, MINIMAP_RATIO, C_WHITE);
	
}

void	draw_minimap(void)
{
	t_cub3d	*cub3d;
	int x;
	int y;

	cub3d = get_cub3d();
	if (cub3d->config.minimap == false)
		return ;

	y = -1;
	while (++y < cub3d->config.map.height)
	{
		x = -1;
		while (cub3d->config.map.map[y][++x])
			draw_minimap_square(y, x);
	}
	draw_player();
	//draw_raypoints();
}
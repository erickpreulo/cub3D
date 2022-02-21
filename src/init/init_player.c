/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:06:28 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 15:59:00 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_position(int x, int y, char c)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	cub3d->player.pos.x = x + 0.5;
	cub3d->player.pos.y = y + 0.5;
	if (c == 'E')
		cub3d->player.pos.angle = 0;
	if (c == 'N')
		cub3d->player.pos.angle = PI / 2;
	if (c == 'W')
		cub3d->player.pos.angle = PI;
	if (c == 'S')
		cub3d->player.pos.angle = 3 * PI / 2;
}

void	get_position_on_map(void)
{
	t_cub3d	*cub3d;
	int		y;
	int		x;
	char	c;
	
	cub3d = get_cub3d();
	c = 0;
	y = -1;
	while (++y < cub3d->config.map.height)
	{
		x = -1;
		while (cub3d->config.map.map[y][++x])
		{
			c = cub3d->config.map.map[y][x];
			if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player_position(x, y, c);
				cub3d->config.map.map[y][x] = '0';
				return ;
			}
		}
	}
}

void	init_player(void)
{
	t_cub3d	*cub3d;
	
	cub3d = get_cub3d();
	cub3d->player.pos.x = 0;
	cub3d->player.pos.y = 0;
	cub3d->player.pos.angle = 0;
	cub3d->player.state.movingUp = false;
	cub3d->player.state.movingDown = false;
	cub3d->player.state.movingLeft = false;
	cub3d->player.state.movingRight = false;
	cub3d->player.state.rotatingLeft = false;
	cub3d->player.state.rotatingRight = false;
	get_position_on_map();
}
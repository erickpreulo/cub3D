/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:22 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	smart_position(double perc_x, double perc_y)
{
	t_player	*player;
	t_cub3d		*cub3d;
	t_position	temp_h;
	t_position	temp_v;

	cub3d = get_cub3d();
	player = &cub3d->player;
	temp_h.x = player->pos.x + 10 * perc_x * PLAYER_STEP;
	temp_h.y = player->pos.y;
	temp_v.x = player->pos.x;
	temp_v.y = player->pos.y + 10 * perc_y * PLAYER_STEP;
	if (cub3d->config.map.map[(int)temp_h.y][(int)temp_h.x] != '1')
		player->pos.x += perc_x * PLAYER_STEP * player->speed;

	if (cub3d->config.map.map[(int)temp_v.y][(int)temp_v.x] != '1')
		player->pos.y += perc_y * PLAYER_STEP * player->speed;

}

void	update_player(void)
{
	t_player	*player;

	player = &get_cub3d()->player;
	if (player->state.movingUp)
		smart_position(cos(player->pos.angle), -sin(player->pos.angle));
	if (player->state.movingDown)
		smart_position(-cos(player->pos.angle), sin(player->pos.angle));
	if (player->state.movingLeft)
		smart_position(-sin(player->pos.angle), -cos(player->pos.angle));
	if (player->state.movingRight)
		smart_position(sin(player->pos.angle), cos(player->pos.angle));
	if (player->state.rotatingLeft)
		player->pos.angle += PLAYER_STEP * player->speed;
	if (player->state.rotatingRight)
		player->pos.angle -= PLAYER_STEP * player->speed;
	player->pos = fix_boundaries(player->pos);
}

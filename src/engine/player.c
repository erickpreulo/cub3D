/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 13:09:58 by egomes           ###   ########.fr       */
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
	if (player->state.movingup)
		smart_position(cos(player->pos.angle), -sin(player->pos.angle));
	if (player->state.movingdown)
		smart_position(-cos(player->pos.angle), sin(player->pos.angle));
	if (player->state.movingleft)
		smart_position(-sin(player->pos.angle), -cos(player->pos.angle));
	if (player->state.movingright)
		smart_position(sin(player->pos.angle), cos(player->pos.angle));
	if (player->state.rotatingleft)
		player->pos.angle += PLAYER_STEP * player->speed;
	if (player->state.rotatingright)
		player->pos.angle -= PLAYER_STEP * player->speed;
	player->pos = fix_boundaries(player->pos);
}

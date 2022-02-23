/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 00:31:40 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	smart_position(double perc_x, double perc_y)
{
	t_player	*player;
	t_cub3d		*cub3d;
	t_position	temp;

	cub3d = get_cub3d();
	player = &cub3d->player;
	temp.x = player->pos.x + 2 * perc_x * PLAYER_STEP;
	temp.y = player->pos.y + 2 * perc_y * PLAYER_STEP;
	if (cub3d->config.map.map[(int)player->pos.y][(int)temp.x] != '1')
		player->pos.x += perc_x * PLAYER_STEP;
	if (cub3d->config.map.map[(int)temp.y][(int)player->pos.x] != '1')
		player->pos.y += perc_y * PLAYER_STEP;

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
		player->pos.angle += PLAYER_STEP;
	if (player->state.rotatingRight)
		player->pos.angle -= PLAYER_STEP;
	player->pos = fix_boundaries(player->pos);
}

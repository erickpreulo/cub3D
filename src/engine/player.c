/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 15:34:55 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	smart_position(double perc_x, double perc_y)
{
	t_player	*player;

	player = &get_cub3d()->player;

	player->pos.x += perc_x * PLAYER_STEP;
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

}

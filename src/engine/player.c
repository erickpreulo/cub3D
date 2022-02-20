/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:40:23 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/20 11:52:09 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player(void)
{
	t_player	*player;

	player = &get_cub3d()->player;
	if (player->state.movingUp)
		player->pos.y -= PLAYER_STEP;
	if (player->state.movingDown)
		player->pos.y += PLAYER_STEP;
	if (player->state.movingLeft)
		player->pos.x -= PLAYER_STEP;
	if (player->state.movingRight)
		player->pos.x += PLAYER_STEP;
}

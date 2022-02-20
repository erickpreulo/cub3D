/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:34:58 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/20 11:47:14 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_handler(t_cub3d *cub3d)
{
	(void) cub3d;
	update_player();
	update_raycast();
	render();
	return (0);
}
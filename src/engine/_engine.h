/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _engine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:02:30 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/20 11:41:25 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENGINE_H
# define _ENGINE_H

int		loop_handler(t_cub3d *cub3d);
int		key_pressed(int key, t_cub3d *cub3d);
int		key_released(int key, t_cub3d *cub3d);
void	update_player(void);
void	update_raycast(void);

#endif
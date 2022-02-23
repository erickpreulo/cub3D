/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:16:28 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/22 23:39:07 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int key, t_cub3d *cub3d)
{
	if (key == K_W)
		cub3d->player.state.movingUp = true;
	if (key == K_S)
		cub3d->player.state.movingDown = true;
	if (key == K_A)
		cub3d->player.state.movingLeft = true;
	if (key == K_D)
		cub3d->player.state.movingRight = true;
	if (key == K_LEFT)
		cub3d->player.state.rotatingLeft = true;
	if (key == K_RIGHT)
		cub3d->player.state.rotatingRight = true;
	if (key == K_M)
		cub3d->config.minimap = !cub3d->config.minimap;
	if (key == K_PLUS)
		cub3d->config.fov = correct_fov(cub3d->config.fov + 0.1);
	if (key == K_MINUS)
		cub3d->config.fov = correct_fov(cub3d->config.fov - 0.1);
	if (key == K_ESC)
		exit_mlx(cub3d);	
	return (0);
}

int	key_released(int key, t_cub3d *cub3d)
{
	if (key == K_W)
		cub3d->player.state.movingUp = false;
	if (key == K_S)
		cub3d->player.state.movingDown = false;
	if (key == K_A)
		cub3d->player.state.movingLeft = false;
	if (key == K_D)
		cub3d->player.state.movingRight = false;
	if (key == K_LEFT)
		cub3d->player.state.rotatingLeft = false;
	if (key == K_RIGHT)
		cub3d->player.state.rotatingRight = false;
	if (key == K_M)
		printf("M released!\n");
	if (key == K_PLUS)
		printf("+ released!\n");
	if (key == K_MINUS)
		printf("- released!\n");
	return (0);
}
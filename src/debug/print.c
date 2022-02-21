/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:30:35 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 14:44:49 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(void)
{
	t_cub3d *cub3d = get_cub3d();

	printf("\n=== PLAYER ===\n");
	printf("> Player->pos.x: %f\n", cub3d->player.pos.x);
	printf("> Player->pos.y: %f\n", cub3d->player.pos.y);
	printf("> Player->pos.angle: %f\n", cub3d->player.pos.angle);
	printf("=== END PLAYER ===\n");
}

void	print_info()
{
	t_cub3d *cub3d = get_cub3d();

	printf("\n=== INFO ===\n");
	printf("> Texture NO: %s\n", cub3d->config.textures[NO]);
	printf("> Texture SO: %s\n", cub3d->config.textures[SO]);
	printf("> Texture WE: %s\n", cub3d->config.textures[WE]);
	printf("> Texture EA: %s\n", cub3d->config.textures[EA]);
	t_color floor = get_color(cub3d->config.floor);
	printf("> Floor: RGB: (%d,%d,%d)\n", floor.r, floor.g, floor.b);
	t_color ceilling = get_color(cub3d->config.ceilling);
	printf("> Ceilling: RGB: (%d,%d,%d)\n", ceilling.r, ceilling.g, ceilling.b);
	printf("=== END INFO ===\n");
}


void	print_map()
{
	t_cub3d *cub3d = get_cub3d();

	printf("\n=== MAP ===\n");
	if (!cub3d->config.map.map)
		return ((void)printf("Map not implemented!\n"));
	printf("> Map Height: %d\n", cub3d->config.map.height);
	printf("> Map Width: %d\n", cub3d->config.map.width);
	int i = -1;
	while (cub3d->config.map.map[++i])
		printf("[%d]	%s\n", i, cub3d->config.map.map[i]);
	printf("=== END MAP ===\n");
}

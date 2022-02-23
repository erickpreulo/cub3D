/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:40:26 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 11:17:07 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_wall(int i, double dist, t_cub3d *cub3d)
{
	int j;
	const int	size = 320 / dist;

	j = (WINDOW_HEIGHT / 2) - size;
	while (++j < (WINDOW_HEIGHT / 2) + size)
	{
		if (j < 0 || j > WINDOW_HEIGHT - 1)
			continue;
		if (cub3d->ray[i].pos.direction == NO)
			my_mlx_pixel_put(&cub3d->img, i, j, C_BLUE);
		if (cub3d->ray[i].pos.direction == SO)
			my_mlx_pixel_put(&cub3d->img, i, j, C_GREEN);
		if (cub3d->ray[i].pos.direction == EA)
			my_mlx_pixel_put(&cub3d->img, i, j, C_RED);
		if (cub3d->ray[i].pos.direction == WE)
			my_mlx_pixel_put(&cub3d->img, i, j, C_BLACK);
	}
}

void	draw_walls(void)
{
	t_cub3d	*cub3d;
	int		i;

	cub3d = get_cub3d();
	i = -1;
	while (++i < WINDOW_WIDTH)
		draw_line_wall(i, cub3d->ray[i].dist, cub3d);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:40:26 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 14:07:26 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_wall(int i, double dist, t_cub3d *cub3d)
{
	int j;
	t_texture	*t;
	int *temp;
	const int	size = (WINDOW_HEIGHT / 2) / dist;

	j = (WINDOW_HEIGHT / 2) - size;
	t = &cub3d->config.textures[cub3d->rays[i].pos.direction];
	temp = (int *)&(t->img.addr);
	while (++j < (WINDOW_HEIGHT / 2) + size)
	{
		if (j < 0 || j > WINDOW_HEIGHT - 1)
			continue;
		my_mlx_pixel_put(&cub3d->img, i, j, invert_color(temp[0]));

	}
}

void	draw_walls(void)
{
	t_cub3d	*cub3d;
	int		i;

	cub3d = get_cub3d();
	i = -1;
	while (++i < WINDOW_WIDTH)
		draw_line_wall(i, cub3d->rays[i].dist, cub3d);

}
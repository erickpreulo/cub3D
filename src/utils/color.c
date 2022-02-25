/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:47:09 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 10:12:28 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	apply_shadow(int color, double dist)
{
	double	div;

	div = dist / 0.5;
	if (div <= 1)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / div) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / div) << 8)
		+ ((int)((0x0000FF & color) / div)));
}

int	apply_shadow_background(int color, double y)
{
	double	div;

	div = fabs(y - (WINDOW_HEIGHT / 2)) / (WINDOW_HEIGHT / 2) * 0.7;
	return (((int)(((0xFF0000 & color) >> 16) * div) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) * div) << 8)
		+ ((int)((0x0000FF & color) * div)));
}

t_color	get_color(int c)
{	
	t_color	color;

	color.b = (c) & 0xff;
	color.g = (c >> 8) & 0xff;
	color.r = (c >> 16) & 0xff;
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:47:09 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 13:14:07 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

t_color	get_color(int c)
{	
	t_color color;

	color.b = (c) & 0xff;
	color.g = (c >> 8) & 0xff;
	color.r = (c >> 16) & 0xff;
	return (color);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _draw.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:02:30 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 10:04:03 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_square(t_position start, int width, int height, int color);
void	render(void);
void	draw_ceilling(void);
void	draw_floor(void);
void	draw_minimap(void);

#endif
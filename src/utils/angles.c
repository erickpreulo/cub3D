/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:40:19 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 00:17:13 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	correct_angle(double angle)
{
	if (angle >= 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

double	correct_fov(double fov)
{
	if (fov > PI)
		fov = PI;
	if (fov < PI / 10)
		fov = PI / 10;
	return (fov);
}
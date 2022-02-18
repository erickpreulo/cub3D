/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:28:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/18 08:36:34 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*get_cub3d(void)
{
	static t_cub3d	*cub3d;

	if (!cub3d)
		cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		exit(0);
	return (cub3d);
}
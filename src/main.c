/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:12:02 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/19 09:15:09 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d *cub3d;

	cub3d = get_cub3d();
	init(argc, argv);
	render();
	mlx_loop(cub3d->mlx);
	safe_exit();
	return (0);
}	
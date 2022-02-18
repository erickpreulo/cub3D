/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:35:42 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/18 19:32:54 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map()
{
	t_cub3d	*cub3d;
	
	cub3d = get_cub3d();
	cub3d->config.map.map = ft_calloc(100, sizeof(char *));
	if (!cub3d->config.map.map)
		exit_error("Calloc of map failed");
	cub3d->config.map.height = 0;
	cub3d->config.map.width = 0;
	
}

void	init(int argc, char **argv)
{
	t_cub3d	*cub3d = get_cub3d();

	if (argc != 2)
		exit_error("cub3d has only 1 argument, a .cub config file!");
	cub3d->config.file = argv[1];
	init_map();
	read_file();

	// DEBUG
	print_info();
	print_map();
}
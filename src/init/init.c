/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:35:42 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/18 21:14:26 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx()
{
	t_cub3d	*cub3d;
	
	cub3d = get_cub3d();

	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WINDOW_WIDTH,
										WINDOW_HEIGHT, "CUB3D!");
	cub3d->img.img = mlx_new_image(cub3d->mlx,
										WINDOW_WIDTH, WINDOW_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img,
											&cub3d->img.bpp,
											&cub3d->img.line_length,
											&cub3d->img.endian);

	// mlx_hook(fractol->win.win, 2, 1L<<0, key_hook, fractol);
	// mlx_mouse_hook(fractol->win.win, mouse_hook, fractol);
	// mlx_hook(fractol->win.win, 6, 1L << 6, hook_mousemove, fractol);
	mlx_hook(cub3d->win, 33, 1L << 17, exit_mlx, cub3d);
}

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
	init_mlx();

	for (int i = 0; i < WINDOW_WIDTH; i++)
		for (int j = 0; j < WINDOW_HEIGHT; j++)
			my_mlx_pixel_put(&cub3d->img, i, j, cub3d->config.ceilling);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	mlx_loop(cub3d->mlx);
}
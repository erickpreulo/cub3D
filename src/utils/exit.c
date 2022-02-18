/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:39:41 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/18 21:12:32 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_mlx(t_cub3d *cub3d)
{
	if (cub3d && cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d && cub3d->img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	safe_exit();
	printf("Bye bye!\n");
	exit(0);
}

void	free_split(char **data)
{
	int i;

	i = -1;
	if (data)
	{
		while (data[++i])
			free(data[i]);
		free(data);
	}
}

void	free_if_exists(void *data)
{
	if (data)
		free(data);
}

void	safe_exit()
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	free_if_exists(cub3d->config.textures[NO]);
	free_if_exists(cub3d->config.textures[SO]);
	free_if_exists(cub3d->config.textures[WE]);
	free_if_exists(cub3d->config.textures[EA]);
	free_split(cub3d->config.map.map);
	free(cub3d);
}


void	exit_error(char *msg)
{
	safe_exit();
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO); 
	exit(EXIT_FAILURE);
}
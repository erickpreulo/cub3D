/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:39:41 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 13:32:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_mlx(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	safe_exit();
	printf("Bye bye!\n");
	exit(0);
}

void	free_split(char **data)
{
	int	i;

	i = -1;
	if (data)
	{
		while (data[++i])
			free(data[i]);
		free(data);
	}
}

void	safe_exit(void)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	if (cub3d->mlx && cub3d->config.textures[NO].img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->config.textures[NO].img.img);
	if (cub3d->config.textures[NO].path)
		free(cub3d->config.textures[NO].path);
	if (cub3d->mlx && cub3d->config.textures[SO].img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->config.textures[SO].img.img);
	if (cub3d->config.textures[SO].path)
		free(cub3d->config.textures[SO].path);
	if (cub3d->mlx && cub3d->config.textures[WE].img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->config.textures[WE].img.img);
	if (cub3d->config.textures[WE].path)
		free(cub3d->config.textures[WE].path);
	if (cub3d->mlx && cub3d->config.textures[EA].img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->config.textures[EA].img.img);
	if (cub3d->config.textures[EA].path)
		free(cub3d->config.textures[EA].path);
	if (cub3d->mlx && cub3d->config.logo.img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->config.logo.img.img);
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

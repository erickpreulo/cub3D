/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:36:43 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 12:55:11 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validation(void)
{
	t_cub3d *cub3d;
	int i;
	int j;
	int player;

	player = 0;
	cub3d = get_cub3d();
	i = 0;
	while (cub3d->config.map.map[i] != NULL)
	{
		j = 0;
		while (cub3d->config.map.map[i][j] != '\0')
		{
			if ((j == 0) || (i == 0) || (j == cub3d->config.map.width - 1) || (i == cub3d->config.map.height - 1))
			{
				if (cub3d->config.map.map[i][j] != ' ' && cub3d->config.map.map[i][j] != '1')
				{
					printf("Error1: MAP\n[%s]\n", cub3d->config.map.map[i]);
					exit_error("MAP\n");
				}
			}
			else if (cub3d->config.map.map[i][j] == ' ')
			{
				if ((cub3d->config.map.map[i - 1][j] != ' ' && cub3d->config.map.map[i - 1][j] != '1')
					|| (cub3d->config.map.map[i][j - 1] != ' ' && cub3d->config.map.map[i][j - 1] != '1')
					|| (cub3d->config.map.map[i + 1][j] != ' ' && cub3d->config.map.map[i + 1][j] != '1')
					|| (cub3d->config.map.map[i][j + 1] != ' ' && cub3d->config.map.map[i][j + 1] != '1'))
				{
					printf("Error2: MAP\n[%s]\n", cub3d->config.map.map[i]);
					exit_error("MAP\n");
				}
			}
			if (cub3d->config.map.map[i][j] != '0'
				&& cub3d->config.map.map[i][j] != ' '
				&& cub3d->config.map.map[i][j] != '1'
				&& cub3d->config.map.map[i][j] != 'N'
				&& cub3d->config.map.map[i][j] != 'S'
				&& cub3d->config.map.map[i][j] != 'O'
				&& cub3d->config.map.map[i][j] != 'L')
			{
				printf("Error3: MAP\n[%s]\n", cub3d->config.map.map[i]);
				exit_error("MAP\n");
			}
			if (cub3d->config.map.map[i][j] == 'N' || cub3d->config.map.map[i][j] == 'S'
				|| cub3d->config.map.map[i][j] == 'O' || cub3d->config.map.map[i][j] == 'L')
			{
				if (player)
				{
					printf("Error3: MAP\n[%s]\n", cub3d->config.map.map[i]);
					exit_error("MAP\n");
				}
				player = 1;
			}
			j++;
		}
		i++;
	}
}

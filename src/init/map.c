/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:36:43 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/24 13:27:11 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validation_map_possible_characters(t_cub3d *cub3d, int i, int j)
{
	if (cub3d->config.map.map[i][j] != '0'
		&& cub3d->config.map.map[i][j] != ' '
		&& cub3d->config.map.map[i][j] != '1'
		&& cub3d->config.map.map[i][j] != 'N'
		&& cub3d->config.map.map[i][j] != 'S'
		&& cub3d->config.map.map[i][j] != 'W'
		&& cub3d->config.map.map[i][j] != 'E')
		exit_error("MAP Character");
}

void	validation_map_shape(t_cub3d *cub3d, int i, int j)
{
	if ((j == 0) || (i == 0)
		|| (j == cub3d->config.map.width - 1)
		|| (i == cub3d->config.map.height - 1))
	{
		if (cub3d->config.map.map[i][j] != ' '
			&& cub3d->config.map.map[i][j] != '1')
			exit_error("MAP Shape");
	}
	else if (cub3d->config.map.map[i][j] == ' ')
	{
		if ((cub3d->config.map.map[i - 1][j] != ' '
			&& cub3d->config.map.map[i - 1][j] != '1')
			|| (cub3d->config.map.map[i][j - 1] != ' '
			&& cub3d->config.map.map[i][j - 1] != '1')
			|| (cub3d->config.map.map[i + 1][j] != ' '
			&& cub3d->config.map.map[i + 1][j] != '1')
			|| (cub3d->config.map.map[i][j + 1] != ' '
			&& cub3d->config.map.map[i][j + 1] != '1'))
			exit_error("MAP Shape");
	}
	validation_map_possible_characters(cub3d, i, j);
}

bool	find_player(t_cub3d *cub3d, int i, int j)
{
	if (cub3d->config.map.map[i][j] == 'N'
		|| cub3d->config.map.map[i][j] == 'S'
		|| cub3d->config.map.map[i][j] == 'W'
		|| cub3d->config.map.map[i][j] == 'E')
		return (true);
	return (false);
}

void	validation_map(void)
{
	t_cub3d	*cub3d;
	int		i;
	int		j;
	int		player;

	player = 0;
	cub3d = get_cub3d();
	i = -1;
	while (cub3d->config.map.map[++i] != NULL)
	{
		j = -1;
		while (cub3d->config.map.map[i][++j] != '\0')
		{
			validation_map_shape(cub3d, i, j);
			if (find_player(cub3d, i, j))
			{
				if (player)
					exit_error("MAP Player");
				player++;
			}
		}
	}
	if (player == 0)
		exit_error("Where is the player?");
}

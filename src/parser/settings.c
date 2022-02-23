/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:35:03 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 00:09:29 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_background(char *line, char c)
{
	t_cub3d		*cub3d;
	char		**colors;
	int			i;

	cub3d = get_cub3d();
	i = 1;
	while (line[++i] != '\0')
		if (line[i] != ',' && line[i] != ' ' && !ft_isdigit(line[i]))
			exit_error("Background (F or C) has invalid char");
	i = 1;
	while (i == ' ' && i < ft_strlen(line))
		i++;
	colors = ft_split(line + i, ',');
	if (!colors)
		exit_error("Error on split background (F or C)");
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		exit_error("Background (F or C) must have 3 colors");
	if (c == 'F')
		cub3d->config.floor = create_color(ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]));
	else
		cub3d->config.ceilling = create_color(ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]));
	free_split(colors);
}

void	set_texture(t_texture index, char *line)
{
	const int	len = ft_strlen(line);
	t_cub3d		*cub3d;
	char		*texture;
	int 		i;

	cub3d = get_cub3d();
	i = 2;
	while (i == ' ')
	{
		i++;
		if (i == len - 1)
			exit_error("Texture with invalid format");
	}
	texture = ft_substr(line, i, len - i);
	if (!texture)
		exit_error("Malloc of texture failed");
	cub3d->config.textures[index] = texture;

}

void	parse_settings(char *line)
{
	static bool in_map = false;
	
	if (!ft_strcmp(line, "\0") && in_map)
		return(exit_error("Map cut"));
	if (!ft_strcmp(line, "\0"))
		return ;
	if (!ft_strncmp(line, "NO ", 3))
		return(set_texture(NO, line));
	if (!ft_strncmp(line, "SO ", 3))
		return(set_texture(SO, line));
	if (!ft_strncmp(line, "WE ", 3))
		return(set_texture(WE, line));
	if (!ft_strncmp(line, "EA ", 3))
		return(set_texture(EA, line));
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return(set_background(line, line[0]));
	in_map = true;
	push_to_map(line);
}
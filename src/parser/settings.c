/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:35:03 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 10:44:21 by aneuwald         ###   ########.fr       */
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

void	set_texture(t_direction dir, char *line)
{
	t_cub3d	*cub3d;
	char	*texture_path;
	char	*ext;

	cub3d = get_cub3d();
	ext = ft_strrchr(line, '.');
	if (!ext || ft_strcmp(ext, ".xpm"))
		exit_error("Texture must have .xpm extension");
	texture_path = ft_strdup(ft_strchr(line, '.'));
	if (!texture_path)
		exit_error("Error on malloc texture_path");
	if (cub3d->config.textures[dir].path)
		exit_error("Duplicated texture key");
	cub3d->config.textures[dir].path = texture_path;
}

void	check_all_settings()
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	if (!cub3d->config.textures[NO].path)
		exit_error("Where is the NO texture?");
	if (!cub3d->config.textures[SO].path)
		exit_error("Where is the SO texture?");
	if (!cub3d->config.textures[WE].path)
		exit_error("Where is the WE texture?");
	if (!cub3d->config.textures[EA].path)
		exit_error("Where is the EA texture?");
	if (cub3d->config.floor == -1)
		exit_error("Floor must have a color");
	if (cub3d->config.ceilling == -1)
		exit_error("Ceilling must have a color");
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
	check_all_settings();
	push_to_map(line);
}
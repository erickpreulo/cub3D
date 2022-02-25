/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:35:03 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 10:53:48 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_verification(t_cub3d *cub3d, int c, char **colors)
{
	int	r;
	int	g;
	int	b;

	verify_color_chars(colors);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r > 255 || g > 255 || b > 255)
		exit_error
			("Do you really believe that exist a color with this number?");
	if (c == 'F')
		cub3d->config.floor = create_color((char)r,
				(char)g, (char)b);
	else
		cub3d->config.ceilling = create_color((char)r,
				(char)g, (char)b);
}

void	set_background(char *line, char c)
{
	t_cub3d		*cub3d;
	char		**colors;
	int			i;

	cub3d = get_cub3d();
	i = 1;
	while (line[++i] != '\0')
		if (line[i] != ',' && !ft_isspace(line[i]) && !ft_isdigit(line[i]))
			exit_error("Background (F or C) has invalid char");
	i = 1;
	while (ft_isspace(line[i]) && line[i] != '\0')
		i++;
	colors = ft_split(line + i, ',');
	if (!colors)
		exit_error("Error on split background (F or C)");
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		exit_error("Background (F or C) must have 3 colors");
	f_verification(cub3d, c, colors);
	free_split(colors);
}

void	set_texture(t_direction dir, char *line)
{
	t_cub3d	*cub3d;
	char	*texture_path;
	char	*ext;

	cub3d = get_cub3d();
	texture_path = ft_strtrim(line + 2, " \t");
	if (!texture_path)
		exit_error("Error on ft_strtrim texture_path");
	ext = ft_strrchr(texture_path, '.');
	if (!ext || ft_strcmp(ext, ".xpm"))
		exit_error("Texture must have .xpm extension");
	if (cub3d->config.textures[dir].path)
		exit_error("Duplicated texture key");
	cub3d->config.textures[dir].path = texture_path;
}

void	check_all_settings(void)
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
	static bool	in_map = false;

	if (!ft_strcmp(line, "\0") && in_map)
		return (exit_error("Map cut"));
	if (!ft_strcmp(line, "\0"))
		return ;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO\t", 3))
		return (set_texture(NO, line));
	if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO\t", 3))
		return (set_texture(SO, line));
	if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE\t", 3))
		return (set_texture(WE, line));
	if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA\t", 3))
		return (set_texture(EA, line));
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2)
		|| !ft_strncmp(line, "F\t", 2) || !ft_strncmp(line, "C\t", 2))
		return (set_background(line, line[0]));
	in_map = true;
	check_all_settings();
	push_to_map(line);
}

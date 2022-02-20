/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:05:57 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/20 00:38:25 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	append_spaces(char **row)
{
	t_cub3d	*cub3d;
	char	*new_str;
	char	*temp;
	int		i;

	cub3d = get_cub3d();
	temp = *row;
	new_str = malloc((cub3d->config.map.width + 2) * sizeof(char));
	if (!new_str)
		exit_error("Malloc failed on append spaces");
	i = -1;
	while ((*row)[++i])
		new_str[i] = (*row)[i];
	while (i < cub3d->config.map.width)
		new_str[i++] = ' ';
	new_str[i] = '\0';
	*row = new_str;
	free(temp);
}

void	fix_map_rows(void)
{
	t_cub3d	*cub3d;
	int 	i;
	int		len;

	cub3d = get_cub3d();
	i = -1;
	while (++i < cub3d->config.map.height)
	{
		len = ft_strlen(cub3d->config.map.map[i]);
		if (len < cub3d->config.map.width)
			append_spaces(&cub3d->config.map.map[i]);
	}
}

void	push_char(char c, char *row)
{
	int i;
	int	correct_char;

	correct_char = c;
	if (c == '\t')
		correct_char = ' ';

	i = 0;
	while(row[i])
		i++;
	row[i] = correct_char;
	if (c != '\t')
		return;
	row[++i] = correct_char;
	row[++i] = correct_char;
	row[++i] = correct_char;

}

void	push_to_map(char *line)
{
	t_cub3d 	*cub3d;
	int			len;
	int			i;
	int			index;

	cub3d = get_cub3d();
	index = cub3d->config.map.height;
	len = ft_strlen(line);
	i = -1;
	while(line[++i] != '\0')
		if (line[++i] == '\t')
			len += 3;
	if (len > cub3d->config.map.width)
		cub3d->config.map.width = len;
	cub3d->config.map.map[index] = ft_calloc(len + 1, sizeof(char));
	if (!cub3d->config.map.map[index])
		exit_error("Calloc failed on creating map row");
	i = -1;
	while(line[++i] != '\0')
		push_char(line[i], cub3d->config.map.map[index]);
	cub3d->config.map.height++;
}
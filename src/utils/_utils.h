/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:40:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/18 20:55:51 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

void	exit_error(char *msg);
void	safe_exit();
void	free_split(char **data);
int		create_color(int r, int g, int b);
t_color	get_color(int c);
int		exit_mlx(t_cub3d *cub3d);

#endif
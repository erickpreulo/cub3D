/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:40:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/22 11:18:32 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

void		exit_error(char *msg);
void		safe_exit();
void		free_split(char **data);
int			create_color(int r, int g, int b);
t_color		get_color(int c);
int			exit_mlx(t_cub3d *cub3d);
double		correct_angle(double angle);
t_position	fix_boundaries(t_position pos);
double		calc_dist(t_position pos1, t_position pos2);
t_position	new_position(void);
t_position	limit_position(void);

#endif
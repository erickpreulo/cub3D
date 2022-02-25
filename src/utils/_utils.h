/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:40:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 10:53:05 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

void		exit_error(char *msg);
void		safe_exit(void);
void		free_split(char **data);
int			create_color(int r, int g, int b);
t_color		get_color(int c);
int			exit_mlx(t_cub3d *cub3d);
double		correct_angle(double angle);
double		correct_fov(double fov);
t_position	fix_boundaries(t_position pos);
double		calc_dist(t_position pos1, t_position pos2);
t_position	new_position(void);
t_position	limit_position(void);
int			apply_shadow(int color, double dist);
int			apply_shadow_background(int color, double y);
void		verify_color_chars(char **colors);

#endif
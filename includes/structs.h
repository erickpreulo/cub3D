/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:16:08 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/25 10:03:28 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_direction
{
	NO,
	SO,
	WE,
	EA
}				t_direction;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_state
{
	bool		movingup;
	bool		movingdown;
	bool		movingleft;
	bool		movingright;
	bool		rotatingleft;
	bool		rotatingright;
}				t_state;

typedef struct s_position
{
	double		x;
	double		y;
	double		angle;
	t_direction	direction;
}				t_position;

typedef struct s_player
{
	t_position	pos;
	t_state		state;
	int			speed;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct s_image {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_texture {
	t_image		img;
	char		*path;
	int			width;
	int			height;
}				t_texture;

typedef struct s_hud
{
	bool		minimap;
	bool		logo;
	bool		ray;
}					t_hud;

typedef struct s_config
{
	t_texture	textures[4];
	t_texture	logo;
	int			floor;
	int			ceilling;
	t_map		map;
	char		*file;
	t_hud		hud;
	int			last_x;
	double		fov;
	double		dr;
}				t_config;

typedef struct s_ray
{
	double		dist;
	t_position	pos;
}					t_ray;

typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_image		img;
	t_config	config;	
	t_player	player;
	t_ray		rays[WINDOW_WIDTH];
}				t_cub3d;

#endif
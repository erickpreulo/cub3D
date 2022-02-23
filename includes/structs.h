/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:16:08 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 00:17:13 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum	s_texture
{
	NO,
	SO,
	WE,
	EA
}				t_texture;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_state
{
	bool		movingUp;
	bool		movingDown;
	bool		movingLeft;
	bool		movingRight;
	bool		rotatingLeft;
	bool		rotatingRight;
}				t_state;

typedef struct	s_position
{
	double		x;
	double		y;
	double		angle;
	t_texture	texture;
}				t_position;

typedef struct	s_player
{
	t_position	pos;
	t_state		state;
}				t_player;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_config
{
	double		fov;
	char		*textures[4];
	int			floor;
	int			ceilling;
	t_map		map;
	char		*file;
	bool		minimap;
}				t_config;

typedef struct	s_image {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_ray
{
	double		dist;
	t_position	pos;
}					t_ray;


typedef struct	s_cub3d
{
	void		*win;
	void		*mlx;
	t_image		img;
	t_config	config;	
	t_player	player;
	t_ray		ray[WINDOW_WIDTH];
}				t_cub3d;


#endif
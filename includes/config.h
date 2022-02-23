/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:16:05 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/23 10:50:55 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//	WINDOW
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700

//	MINIMAP
# define MINIMAP_RATIO 10
# define MINIMAP_OFFSET 20
# define PLAYER_SIZE 5

//	COLORS
# define C_BLACK 0x000000
# define C_WHITE 0xffffff
# define C_GRAY 0x999999
# define C_RED 0xff0000
# define C_GREEN 0x00ff00
# define C_BLUE 0x0000ff

#ifdef __linux__ // LINUX

# define PLAYER_STEP 0.01

//	KEYS
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100

# define K_LEFT 65361
# define K_RIGHT 65363

# define K_M 109
# define K_ESC 65307

#else // MAC

# define PLAYER_STEP 0.05

//	KEYS
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2

# define K_LEFT 123
# define K_RIGHT 124

# define K_M 49
# define K_ESC 53

#endif

//	MATH
# define PI 3.14159265358979323846
# define PLAYER_FOV (PI / 3)
# define DR (PLAYER_FOV / WINDOW_WIDTH)

#endif
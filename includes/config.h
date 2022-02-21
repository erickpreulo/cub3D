/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:16:05 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 16:01:46 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//	WINDOW
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 801

//	MINIMAP
# define MINIMAP_RATIO 10
# define MINIMAP_OFFSET 20
# define PLAYER_SIZE 5

# define PLAYER_STEP 0.01

//	COLORS
# define C_BLACK 0x000000
# define C_WHITE 0xffffff
# define C_GRAY 0x999999
# define C_RED 0xff0000
# define C_GREEN 0x00ff00
# define C_BLUE 0x0000ff

#ifdef __linux__ 
//	KEYS
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100

# define K_LEFT 65361
# define K_RIGHT 65363

# define K_M 109
# define K_ESC 65307
# define K_PLUS 65451
# define K_MINUS 65453

#else // MAC

# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100

# define K_LEFT 65361
# define K_RIGHT 65363

# define K_M 109
# define K_ESC 65307
# define K_PLUS 65451
# define K_MINUS 65453

#endif

//	MATH
# define PI 3.14159265358979323846

#endif
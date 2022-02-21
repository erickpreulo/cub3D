/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:29:35 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 14:45:06 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INIT_H
# define _INIT_H

t_cub3d	*get_cub3d(void);
void	init_game(int argc, char **argv);
void	init_file(void);
void	init_player(void);
void	init_mlx(void);
void	validation_map(void);

#endif
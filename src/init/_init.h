/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:29:35 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 13:42:38 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INIT_H
# define _INIT_H

t_cub3d	*get_cub3d(void);
void	init(int argc, char **argv);
void	init_file();
void	validation_map(void);

#endif
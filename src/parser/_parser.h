/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:40:32 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/20 00:09:51 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PARSER_H
# define _PARSER_H

void	parse_settings(char *line);
void	push_to_map(char *line);
void	fix_map_rows(void);

#endif
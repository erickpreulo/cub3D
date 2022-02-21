/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:12:02 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/21 19:45:49 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	init_game(argc, argv);
	//	DEBUG
	// print_info();
	//print_map();
	print_player();
	init_mlx();
	safe_exit();
	return (0);
}

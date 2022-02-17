/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:12:02 by aneuwald          #+#    #+#             */
/*   Updated: 2022/02/17 23:56:52 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	printf("Hello Wordl!\n");

	void	*mlx;
	void	*mlx_win;

	char *line;

	get_next_line(&line, 0);
	printf("line = %s\n", line);
	free(line);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	mlx_loop(mlx);
	(void) mlx_win;

	return (0);
}	
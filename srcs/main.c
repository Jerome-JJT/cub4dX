/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 17:28:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// jaune:	0x00FFCE6D
// bleu:	0x0081D5FF

int	main(int argc, char **argv)
{
	t_global	global;
	(void)argc;
	(void)argv;

	init_window(&global.window); // init basics, winodw, quit, display bckg...
	quit_program(&global);

	global.map_datas.map = read_map("assets/map1.cub");
	if (!global.map_datas.map)
		return (1);
	get_map_height(&global.map_datas);
for (int i = 0; i < global.map_datas.map_height; ++i)
	printf("%s\n", global.map_datas.map[i]);

	my_mlx_put_ceiling(&global, 0, 0, BLEU);
	my_mlx_put_floor(&global, 0, WIN_HEIGTH/2, JAUNE);
	init_minimap(&global);
	printf("player horizontal : %d\n", global.player.x);
	printf("player vertical : %d\n", global.player.y);

	//mlx_loop_hook(&global.window.mlx_id, render_next_frame, &global);

	mlx_loop(&global.window.mlx_id);
	return (0);
}

/*
	put background (floor)
	ceiling sera calculé par rapport a la taille des pixels a afficher en vertical
*/
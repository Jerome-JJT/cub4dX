/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:20:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 19:55:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3d.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*
	penser a delete toutes les images (voir la struct au besoin)
	free la map
	la window
*/
int	clean(t_global *global)
{
	//free img minimap
	free_map(global->map_datas.map);
	mlx_destroy_window(global->window.mlx_id, global->window.win_id);
	exit(0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	handle_exit(t_global *global)
{
	mlx_key_hook(global->window.win_id, key_hook, global);
	mlx_hook(global->window.win_id, KEY_EXIT, 0, clean, global);
}
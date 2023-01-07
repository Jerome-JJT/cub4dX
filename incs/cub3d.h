/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:23 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/07 14:55:13 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
#include <sys/stat.h>

# include "mlx.h"
# include "libft.h"


//###############################
//								#
//			DEFINES				#
//								#
//###############################

// Window
# define WIN_WIDTH 1024
# define WIN_HEIGTH 512
# define JAUNE 0x00FFCE6D
# define BLEU 0x0081D5FF

// Minimap
# define MINI_WIDTH 256
# define MINI_HEIGHT 128
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

// Quit game
# define EVENT_KEY_ESC 53
# define EVENT_KEY_EXIT 17

// ascii code for each lowercase letter and arrow
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

//minimap
# define GROUND_PATH
# define WALLS
# define DOORS
# define PLAYER

typedef struct s_window
{
	void	*mlx_id;
	void	*win_id;
	char	*color_ground;
	char	*color_ceiling;
}	t_window;

/*
	on aura 4 variables de type t_img
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*texture_path;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_ray
{
	char		*direction;
	t_player	player;
}	t_ray;

typedef struct s_global
{
	t_window	window;
	t_map		map;
	t_img		floor_img;
	t_img		ceiling_img;
	t_img		minimap;
}	t_global;

//###############################
//								#
//			GENERAL				#
//								#
//###############################

// display ground
void	my_mlx_put_floor(t_global *global, int x, int y, int color);
void	my_mlx_put_ceiling(t_global *global, int x, int y, int color);
// display window
void	init_window(t_window *window);
// handle exit
void	quit_program(t_window *window);

//###############################
//								#
//			IMAGES				#
//								#
//###############################

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_img_struct(t_img *img);
void	create_image(t_img *img, t_window *mlx_id, int width, int height);

//###############################
//								#
//			THE MAP				#
//								#
//###############################

char	**read_map(const char *path_to_file);
void	get_map_height(t_map *map);

//###############################
//								#
//			MINIMAP				#
//								#
//###############################

void	my_mlx_put_sqare(t_global *global, int x, int y, int color);


#endif

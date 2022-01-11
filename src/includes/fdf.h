/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:02:48 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/09 16:27:25 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include "keys.h"

typedef struct s_point
{
	double	x;
	double	y;
	int		last;
}	t_point;

typedef struct s_3Dpoint
{
	double	x;
	double	y;
	double	z;
	int		last;
}	t_3Dpoint;

typedef struct s_img
{
	void	*img;
	int		pbits;
	int		lbytes;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
	t_point	pos;
}	t_img;

typedef struct s_map
{
	t_point		**m2d;
	t_3Dpoint	**m3d;
	int			t_x;
	int			t_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		z_increase;
	double		zoom;
	SDL_Color	color;
}	t_map;

typedef struct s_program
{
	SDL_Window		*winS;
	SDL_Renderer	*rend;
	int				width;
	int				height;
	t_img			img;
	t_map			map;
	t_point			mouse;
	int				mouse_right;
	int				mouse_left;
	char			*filename;
}	t_program;

// controls_utils.c
void		deal_event(SDL_Event e, t_program *p);
void		set_isometric(t_program *p);
void		set_dimetric(t_program *p);
void		set_trimetric(t_program *p);
void		set_color(int key, t_program *p);
// controls.c
void		deal_key(t_program *p, int key);
void		mouse_wheel(t_program *p, SDL_Event e);
void		button_press(t_program *p, int button);
void		button_release(t_program *p, int button);
void		mouse_motion(t_program *p);
// convert_utils.c
void		*free_m2d(t_point ***m2d, int is_allocated);
int			get_3dmap_width(t_3Dpoint **map_3d);
int			get_3dmap_height(t_3Dpoint **map_3d);
// convert.c
t_point		**alloc_2dmap_array(t_3Dpoint **map_3d);
void		convert_to_iso(t_map *mapd, int is_allocated);
// draw.c
void		draw_map(t_program *p);
void		redraw(t_program *p);
// instructions.c
void		draw_instructions(t_program *p);
void		draw_color_instructions(t_program *p);
// map.c
void		parse_map_file(char *filename, t_3Dpoint ***map);
// matrix.c
t_3Dpoint	matmul(t_3Dpoint mul[3], t_3Dpoint mat);
// rotation_matrix.c
t_3Dpoint	**get_rotxyz(t_map mapd);
void		*free_rot(t_3Dpoint **rot);
// utils.c
t_point		get_tpoint(int x, int y);
SDL_Color	get_color(int r, int g, int b);
void		assign_sdl_color(SDL_Color *color, int r, int g, int b);
#endif

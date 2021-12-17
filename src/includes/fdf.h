/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:02:48 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/17 15:28:40 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	int		pbits;
	int		lbytes;
	int		endian;
	char	*buffer;
}	t_img;

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

typedef struct s_map
{
	t_point		**m2d;
	t_3Dpoint	**m3d;
	int			t_x;
	int			t_y;
	double		rot_x;
	double		rot_z;
	double		zoom;
}	t_map;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	img;
	t_map	map;
}	t_program;

// controls.c
int		mouse_event(int button, int x, int y, void *param);
int		deal_key(int key, void *param);
// fdf.c
void	draw_map(t_point **map, t_img *img, int color);
#endif

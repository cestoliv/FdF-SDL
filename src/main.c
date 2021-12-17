/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/15 11:10:30 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "includes/img.h"
#include "includes/fdf.h"
#include "includes/map.h"
#include <stdio.h>

#define KEY_LEFT	65361
#define KEY_UP		65362
#define KEY_RIGHT	65363
#define KEY_DOWN	65364
#define KEY_Z		122
#define KEY_S		115
#define KEY_Q		113
#define KEY_D		100
#define KEY_R		114
#define WHEEL_UP	4
#define WHEEL_DOWN	5

t_point s;
t_point t;

void	draw_2D_map(t_point **map, t_img *img, int color)
{
	int	curX;
	int	curY;

	curX = 0;
	while (map[curX])
	{
		curY = 0;
		while (!map[curX][curY].last)
		{
			if (map[curX + 1])
				img_line_put(img, map[curX][curY], map[curX + 1][curY], color);
			if (!map[curX][curY + 1].last)
				img_line_put(img, map[curX][curY], map[curX][curY + 1], color);
			curY++;
		}
		curX++;
	}
}

int mouse_event(int button, int x, int y, void *param)
{
	t_program *p;

	p = param;
	if (button == WHEEL_UP)
		p->map.zoom *= 1.3;
	else if (button == WHEEL_DOWN)
		p->map.zoom /= 1.3;

	ft_putnbr_fd(button, 1);

	img_init_background(&p->img, 1000, 1000, 0x000000);
	p->map.m2d = convert_to_iso(p->map.m3d, p->map);
	draw_2D_map(p->map.m2d, &p->img, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}

int	deal_key(int key, void *param)
{
	t_program *p;

	p = param;
	if (key == KEY_Q)
		p->map.t_x -= 10;
	else if (key == KEY_Z)
		p->map.t_y -= 10;
	else if (key == KEY_D)
		p->map.t_x += 10;
	else if (key == KEY_S)
		p->map.t_y += 10;
	else if (key == KEY_UP)
		p->map.rot_x += 0.03;
	else if (key == KEY_DOWN)
		p->map.rot_x -= 0.03;
	else if (key == KEY_RIGHT)
		p->map.rot_z += 0.03;
	else if (key == KEY_LEFT)
		p->map.rot_z -= 0.03;
	else if (key == KEY_R)
	{
		p->map.t_x = 250;
		p->map.t_y = 250;
		p->map.zoom = 6;
		p->map.rot_x = 0.7853982;
		p->map.rot_z = 0.6154729;
	}

	ft_putnbr_fd(key, 1);

	img_init_background(&p->img, 1000, 1000, 0x000000);
	p->map.m2d = convert_to_iso(p->map.m3d, p->map);
	draw_2D_map(p->map.m2d, &p->img, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}

int	main()
{
	t_program	p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 1000, 1000, "FDF ocartier");

	p.img.img = mlx_new_image(p.mlx, 1000, 1000);
	p.img.buffer = mlx_get_data_addr(p.img.img, &p.img.pbits, &p.img.lbytes, &p.img.endian);

	img_init_background(&p.img, 1000, 1000, 0x000000);

	parse_map_file("maps/mars.fdf", &p.map.m3d);
	p.map.t_x = 250;
	p.map.t_y = 250;
	p.map.zoom = 6;
	p.map.rot_x = 0.7853982;
	p.map.rot_z = 0.6154729;
	p.map.m2d = convert_to_iso(p.map.m3d, p.map);

	s.x = -1;

	draw_2D_map(p.map.m2d, &p.img, 0xFFFFFF);

	mlx_key_hook(p.win, deal_key, &p);
	mlx_mouse_hook(p.win, mouse_event, &p);

	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
	mlx_loop(p.mlx);
}

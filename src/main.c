/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/13 14:00:36 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "includes/img.h"
#include "includes/fdf.h"
#include "includes/map.h"
#include <stdio.h>

int	deal_key(int key, void *param)
{
	t_program *p;

	p = param;
	img_init_background(&p->img, 500, 500, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}

t_point s;
t_point t;

int mouse_event(int button, int x, int y, void *param)
{
	t_program *p = param;	    
	if (s.x == -1)
	{
		write(1, "s", 1);
		s.x = x;
		s.y = y;
		img_pixel_put(&p->img, x, y, 0xE51F0D);
	}
	else
	{
		write(1, "t", 1);
		t.x = x;
		t.y = y;
		img_line_put(&p->img, s, t, 0xE51F0D);
		s.x = -1;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}

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
			img_pixel_put(img, map[curX][curY].x, map[curX][curY].y, color);

			if (map[curX + 1])
				img_line_put(img, map[curX][curY], map[curX + 1][curY], color);
			if (!map[curX][curY + 1].last)
				img_line_put(img, map[curX][curY], map[curX][curY + 1], color);

			curY++;
		}
		curX++;
	}
}

int	main()
{
	/*
	t_point **map;
	map = malloc(sizeof(t_point *) * 3);
	map[0] = malloc(sizeof(t_point) * 2);
	map[1] = malloc(sizeof(t_point) * 2);
	map[2] = malloc(sizeof(t_point) * 2);
	map[3] = malloc(sizeof(t_point) * 2);

	map[3] = NULL;

	map[0][0].x = 10;
	map[0][0].y = 10;
	map[0][0].last = 0;
	
	map[0][1].x = 10;
	map[0][1].y = 20;
	map[0][1].last = 0;
	
	map[0][2].last = 1;

	map[1][0].x = 20;
	map[1][0].y = 10;
	map[1][0].last = 0;
	
	map[1][1].x = 20;
	map[1][1].y = 20;
	map[1][1].last = 0;
	
	map[1][2].last = 1;

	map[2][0].x = 30;
	map[2][0].y = 10;
	map[2][0].last = 0;

	map[2][1].x = 30;
	map[2][1].y = 20;
	map[2][1].last = 0;

	map[2][2].last = 1;
	*/
	t_3Dpoint	**map;
	t_point		**isomap;
	parse_map_file("maps/42.fdf", &map);
	isomap = convert_to_iso(map);

	printf("(%d, %d, %d)\n", map[2][3].x, map[2][3].y, map[2][3].z);
	printf("(%d, %d)\n", isomap[2][3].x, isomap[2][3].y);

	t_program	p;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 500, 500, "FDF ocartier");

	p.img.img = mlx_new_image(p.mlx, 500, 500);
	p.img.buffer = mlx_get_data_addr(p.img.img, &p.img.pbits, &p.img.lbytes, &p.img.endian);

	img_init_background(&p.img, 500, 500, 0xABCDEF);
	
	s.x = -1;

	draw_2D_map(isomap, &p.img, 0xE51F0D);

	mlx_key_hook(p.win, deal_key, &p);
	mlx_mouse_hook(p.win, mouse_event, &p);

	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
	mlx_loop(p.mlx);
}

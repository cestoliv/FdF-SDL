/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/09 12:27:04 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include <unistd.h>
#include "includes/img.h"
#include "includes/fdf.h"

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

int	main()
{
	t_point s1;
	t_point t1;

	t_program	p;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 500, 500, "FDF ocartier");

	p.img.img = mlx_new_image(p.mlx, 500, 500);
	p.img.buffer = mlx_get_data_addr(p.img.img, &p.img.pbits, &p.img.lbytes, &p.img.endian);

	img_init_background(&p.img, 500, 500, 0xABCDEF);
	
	s1.x = 0;
	s1.y = 0;
	t1.x = 300;
	t1.y = 300;
	img_line_put(&p.img, s1, t1, 0xE51F0D);
	s.x = -1;

	mlx_key_hook(p.win, deal_key, &p);
	mlx_mouse_hook(p.win, mouse_event, &p);

	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
	mlx_loop(p.mlx);
}

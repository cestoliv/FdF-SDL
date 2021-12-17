/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/17 15:32:31 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "includes/img.h"
#include "includes/fdf.h"
#include "includes/map.h"
#include "includes/keys_mac.h"
#include <stdio.h>

int	main()
{
	t_program	p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 1000, 1000, "FDF ocartier");

	mlx_do_key_autorepeaton(p.mlx);

	p.img.img = mlx_new_image(p.mlx, 1000, 1000);
	p.img.buffer = mlx_get_data_addr(p.img.img, &p.img.pbits, &p.img.lbytes, &p.img.endian);

	img_init_background(&p.img, 1000, 1000, 0x000000);
	parse_map_file("maps/cube.fdf", &p.map.m3d);
	p.map.t_x = 250;
	p.map.t_y = 250;
	p.map.zoom = 6;
	p.map.rot_x = 0.7853982;
	p.map.rot_z = 0.6154729;
	p.map.m2d = convert_to_iso(p.map.m3d, p.map);
	draw_map(p.map.m2d, &p.img, 0xFFFFFF);
	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);


	mlx_key_hook(p.win, deal_key, &p);
	mlx_mouse_hook(p.win, mouse_event, &p);
	//mlx_hook(p.win, BUTTON_PRESS, 0L, button_press, &p);
	//mlx_hook(p.win, MOTION_NOTIFY, 0L, mouse_motion, &p);
	mlx_loop(p.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:25 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/17 15:32:22 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys_mac.h"
#include "../includes/img.h"

int	mouse_event(int button, int x, int y, void *param)
{
	t_program	*p;

	p = param;
	if (button == WHEEL_UP)
		p->map.zoom *= 1.3;
	else if (button == WHEEL_DOWN)
		p->map.zoom /= 1.3;
	ft_putnbr_fd(button, 1);
	img_init_background(&p->img, 1000, 1000, 0x000000);
	p->map.m2d = convert_to_iso(p->map.m3d, p->map);
	draw_map(p->map.m2d, &p->img, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}

int	deal_key(int key, void *param)
{
	t_program	*p;

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
/*
int	button_press(int key, void *param)
{
	t_program	*p;

	p = param;
	printf("\nbutton press\n");
	return (0);
}

int	mouse_motion(int x, int y, void *param)
{
	static int	old_x = 0;
	static int	old_y = 0;
	t_program	*p;

	p = param;
	printf("old : %d, x : %d\n", old_x, x);
	/*
	printf("old : %d, x : %d\n", old_x, x);
	if (x > old_x - x)
	{
		p->map.rot_x += 0.03;
		old_x = x;
	}
	else if (x < old_x - x)
	{
		p->map.rot_x -= 0.03;
		old_x = x;
	}
	*/
/*
	p->map.rot_x += 0.1;
	img_init_background(&p->img, 1000, 1000, 0x000000);
	p->map.m2d = convert_to_iso(p->map.m3d, p->map);
	draw_2D_map(p->map.m2d, &p->img, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}
*/

#define BUTTON_PRESS 4
#define MOTION_NOTIFY 6

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/08 13:13:14 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <unistd.h>

typedef struct	s_program
{
	void	*mlx;
	void	*win;

	void	*img;
	int		img_pbits;
	int		img_lbytes;
	int		img_endian;
	char	*img_buffer;
}	t_program;

void	init_image_background(t_program *p, int color)
{
	color = mlx_get_color_value(p->mlx, color);

	for(int y = 0; y < 500; ++y)
	for(int x = 0; x < 500; ++x)
	{
		int pixel = (y * p->img_lbytes) + (x * 4);

	    if (p->img_endian == 1)        // Most significant (Alpha) byte first
		{
        	p->img_buffer[pixel + 0] = (color >> 24);
        	p->img_buffer[pixel + 1] = (color >> 16) & 0xFF;
        	p->img_buffer[pixel + 2] = (color >> 8) & 0xFF;
        	p->img_buffer[pixel + 3] = (color) & 0xFF;
    	}
    	else if (p->img_endian == 0)   // Least significant (Blue) byte first
    	{
        	p->img_buffer[pixel + 0] = (color) & 0xFF;
        	p->img_buffer[pixel + 1] = (color >> 8) & 0xFF;
        	p->img_buffer[pixel + 2] = (color >> 16) & 0xFF;
        	p->img_buffer[pixel + 3] = (color >> 24);
    	}
	}
}

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int	deal_key(int key, void *param)
{
	t_program *p;

	p = param;
	init_image_background(p, 0xFFFFFF);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
	t_program *program = param;	    
	mlx_pixel_put(program->mlx, program->win, x, y, 0xFFFFFF);
	//mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int	main()
{
	t_program	p;
	//void		*mlx_ptr;
	//void		*win_ptr;

	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 500, 500, "FDF ocartier");

	p.img = mlx_new_image(p.mlx, 500, 500);
	p.img_buffer = mlx_get_data_addr(p.img, &p.img_pbits, &p.img_lbytes, &p.img_endian);

	init_image_background(&p, 0xABCDEF);
	
	//mlx_pixel_put(program.mlx, program.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(p.win, deal_key, &p);
	//mlx_mouse_hook(program.win, mouse_event, &program);

	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_loop(p.mlx);
}

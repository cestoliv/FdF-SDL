/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:55:46 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/09 09:59:39 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	init_program(t_program *p)
{
	p->width = 3072;
	p->height = 1920;
	p->img.width = p->width;
	p->img.height = p->height - 128;
	p->img.pos.x = 0;
	p->img.pos.y = 128;
	p->mouse.x = 0;
	p->mouse.y = 0;
	p->mouse_right = 0;
	p->mouse_left = 0;
	p->map.t_x = 250;
	p->map.t_y = 250;
	p->map.zoom = 6;
	p->map.rot_x = 0;
	p->map.rot_y = 0;
	p->map.rot_z = -1.570796;
	assign_sdl_color(&p->map.color, 255, 255, 255);
	p->map.color.a = 255;
	p->map.z_increase = 0.2;
}

char	*get_check_map_file(int argc, char **argv, t_program *p)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : fdf <map file>\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_putstr_fd("Can't read file : ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd("\n", 1);
		exit(EXIT_FAILURE);
	}
	p->filename = argv[1];
	return (argv[1]);
}

void	events_loop(t_program *p)
{
	int			quit;
	SDL_Event	e;
	const int frameDelay = 1000 / FRAMERATE;
	Uint32 frameStart;
	int frameTime;

	quit = 0;
	while (!quit)
	{
    	frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			else
				deal_event(e, p);
		}
		redraw(p);
		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
}

int	main(int argc, char **argv)
{
	t_program	p;

	init_program(&p);
	parse_map_file(get_check_map_file(argc, argv, &p), &p.map.m3d);
	p.map.m2d = alloc_2dmap_array(p.map.m3d);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(EXIT_FAILURE);
	if (SDL_CreateWindowAndRenderer(p.width, p.height,
			SDL_WINDOW_SHOWN, &p.winS, &p.rend) != 0)
		exit(EXIT_FAILURE);
	if (TTF_Init() != 0)
		exit(EXIT_FAILURE);
	events_loop(&p);
	TTF_Quit();
	SDL_DestroyWindow(p.winS);
	SDL_DestroyRenderer(p.rend);
	SDL_Quit();
}

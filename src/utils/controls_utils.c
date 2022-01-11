/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:37:28 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/06 11:34:24 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	deal_event(SDL_Event e, t_program *p)
{
	if (e.type == SDL_KEYDOWN)
		deal_key(p, e.key.keysym.sym);
	else if (e.type == SDL_MOUSEWHEEL)
		mouse_wheel(p, e);
	else if (e.type == SDL_MOUSEBUTTONDOWN)
		button_press(p, e.button.button);
	else if (e.type == SDL_MOUSEBUTTONUP)
		button_release(p, e.button.button);
	else if (e.type == SDL_MOUSEMOTION)
		mouse_motion(p);
}

void	set_isometric(t_program *p)
{
	p->map.rot_x = 0.7853982;
	p->map.rot_y = 0;
	p->map.rot_z = 0.6154729;
	p->map.z_increase = 0.2;
}

void	set_dimetric(t_program *p)
{
	p->map.rot_x = 0.7853982;
	p->map.rot_y = 0;
	p->map.rot_z = 0.4636467;
	p->map.z_increase = 0.2;
}

void	set_trimetric(t_program *p)
{
	p->map.rot_x = 1.047198;
	p->map.rot_y = 0;
	p->map.rot_z = 0.4642576;
	p->map.z_increase = 0.2;
}

void	set_color(int key, t_program *p)
{
	if (key == SDLK_1)
		assign_sdl_color(&p->map.color, 255, 255, 255);
	else if (key == SDLK_2)
		assign_sdl_color(&p->map.color, 0, 128, 0);
	else if (key == SDLK_3)
		assign_sdl_color(&p->map.color, 255, 0, 0);
	else if (key == SDLK_4)
		assign_sdl_color(&p->map.color, 31, 117, 254);
	else if (key == SDLK_5)
		assign_sdl_color(&p->map.color, 255, 255, 0);
	else if (key == SDLK_6)
		assign_sdl_color(&p->map.color, 255, 20, 147);
	else if (key == SDLK_7)
		assign_sdl_color(&p->map.color, 128, 128, 128);
}

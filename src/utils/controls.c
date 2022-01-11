/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:25 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/09 10:17:57 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	deal_key(t_program *p, int key)
{
	if (key == SDLK_i)
		set_isometric(p);
	else if (key == SDLK_r)
		set_dimetric(p);
	else if (key == SDLK_t)
		set_trimetric(p);
	else if (key == SDLK_KP_PLUS)
		p->map.z_increase += 0.005;
	else if (key == SDLK_KP_MINUS)
		p->map.z_increase -= 0.005;
	else
		set_color(key, p);
}

void	mouse_wheel(t_program *p, SDL_Event e)
{
	if (e.wheel.y > 0)
		p->map.zoom *= 1.3;
	else if (e.wheel.y < 0)
		p->map.zoom /= 1.3;
}

void	button_press(t_program *p, int button)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (button == SDL_BUTTON_LEFT)
		p->mouse_left = 1;
	else if (button == SDL_BUTTON_RIGHT)
		p->mouse_right = 1;
	p->mouse.x = x;
	p->mouse.y = y;
}

void	button_release(t_program *p, int button)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (button == SDL_BUTTON_LEFT)
		p->mouse_left = 0;
	else if (button == SDL_BUTTON_RIGHT)
		p->mouse_right = 0;
	p->mouse.x = x;
	p->mouse.y = y;
}

void	mouse_motion(t_program *p)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (p->mouse_right)
	{
		p->map.rot_x += (p->mouse.y - y) / 150;
		p->map.rot_y += (x - p->mouse.x) / 150;
	}
	if (p->mouse_left)
	{
		p->map.t_x += x - p->mouse.x;
		p->map.t_y += y - p->mouse.y;
	}
	if (p->mouse_left || p->mouse_right)
	{
		p->mouse.x = x;
		p->mouse.y = y;
	}
}

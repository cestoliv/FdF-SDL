/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:27 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/08 14:00:42 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	get_tpoint(int x, int y)
{
	t_point	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

SDL_Color	get_color(int r, int g, int b)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 255;
	return (color);
}

void	assign_sdl_color(SDL_Color *color, int r, int g, int b)
{
	(*color).r = r;
	(*color).g = g;
	(*color).b = b;
}

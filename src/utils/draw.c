/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:47:39 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/09 16:27:22 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_program *p)
{
	int		curx;
	int		cury;
	t_point	**map;

	map = p->map.m2d;
	curx = 0;
	while (map[curx])
	{
		cury = 0;
		while (!map[curx][cury].last)
		{
			if (map[curx + 1])
				SDL_RenderDrawLine(p->rend,
					(int)map[curx][cury].x, (int)map[curx][cury].y,
					(int)map[curx + 1][cury].x, (int)map[curx + 1][cury].y);
			if (!map[curx][cury + 1].last)
				SDL_RenderDrawLine(p->rend,
					(int)map[curx][cury].x, (int)map[curx][cury].y,
					(int)map[curx][cury + 1].x, (int)map[curx][cury + 1].y);
			cury++;
		}
		curx++;
	}
}

void	redraw(t_program *p)
{
	SDL_SetRenderDrawColor(p->rend, 0, 0, 0, 255);
	SDL_RenderClear(p->rend);
	convert_to_iso(&p->map, 1);
	SDL_SetRenderDrawColor(p->rend,
		p->map.color.r, p->map.color.g, p->map.color.b, p->map.color.a);
	draw_map(p);
	draw_instructions(p);
	SDL_RenderPresent(p->rend);
}

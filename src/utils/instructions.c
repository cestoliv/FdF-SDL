/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:53:45 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/08 13:36:18 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_text(t_program *p, char *str, t_point pos, int size, SDL_Color c)
{
	TTF_Font	*font;
	SDL_Surface	*text;
	SDL_Texture	*text_texture;
	SDL_Rect	dest;

	font = TTF_OpenFont("src/UbuntuMono-R.ttf", size);
	if (!font)
		exit(EXIT_FAILURE);
	text = TTF_RenderText_Solid(font, str, c);
	if (!text)
		exit(EXIT_FAILURE);
	text_texture = SDL_CreateTextureFromSurface(p->rend, text);
	dest.x = pos.x;
	dest.y = pos.y;
	dest.w = text->w;
	dest.h = text->h;
	SDL_RenderCopy(p->rend, text_texture, NULL, &dest);
	TTF_CloseFont(font);
	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
}

void	draw_rect(t_program *p, t_point pos, t_point size, SDL_Color c)
{
	SDL_Rect	rect;

	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = size.x;
	rect.h = size.y;
	SDL_SetRenderDrawColor(p->rend, c.r, c.g, c.b, c.a);
	SDL_RenderFillRect(p->rend, &rect);
}

void	draw_instructions(t_program *p)
{
	draw_rect(p, get_tpoint(0, 0), get_tpoint(p->width, 155), get_color(21, 21, 21));
	SDL_SetRenderDrawColor(p->rend, 255, 255, 255, 255);
	add_text(p, "FDF - ", get_tpoint(10, 10), 30, get_color(255, 255, 255));
	if (ft_strrchr(p->filename, '/') > 0)
		add_text(p, ft_strrchr(p->filename, '/') + 1, get_tpoint(100, 10), 30, get_color(255, 255, 255));
	else
		add_text(p, p->filename, get_tpoint(100, 10), 30, get_color(255, 255, 255));
	add_text(p, "Left Click + Drag   -> Rotation", get_tpoint(20, 45), 24, get_color(255, 255, 255));
	add_text(p, "Right Click + Drag  -> Translation", get_tpoint(20, 71), 24, get_color(255, 255, 255));
	add_text(p, "Scroll              -> Zoom", get_tpoint(20, 95), 24, get_color(255, 255, 255));
	add_text(p, "+/-                 -> Increase Z", get_tpoint(20, 119), 24, get_color(255, 255, 255));
	add_text(p, "T  -> Trimetric Projection", get_tpoint(500, 45), 24, get_color(255, 255, 255));
	add_text(p, "R  -> Dimetric Projection", get_tpoint(500, 71), 24, get_color(255, 255, 255));
	add_text(p, "I  -> Isometric Projection", get_tpoint(500, 95), 24, get_color(255, 255, 255));
	draw_color_instructions(p);
}

void	draw_color_instructions(t_program *p)
{
	add_text(p, "1 - White", get_tpoint(900, 43), 24, get_color(255, 255, 255));
	add_text(p, "2 - Green", get_tpoint(900, 69), 24, get_color(255, 255, 255));
	add_text(p, "3 - Red", get_tpoint(900, 93), 24, get_color(255, 255, 255));
	add_text(p, "4 - Blue", get_tpoint(900, 117), 24, get_color(255, 255, 255));
	add_text(p, "5 - Yellow", get_tpoint(1075, 43), 24, get_color(255, 255, 255));
	add_text(p, "6 - Pink", get_tpoint(1075, 69), 24, get_color(255, 255, 255));
	add_text(p, "7 - Grey", get_tpoint(1075, 93), 24, get_color(255, 255, 255));
	draw_rect(p, get_tpoint(875, 48), get_tpoint(15, 15), get_color(255, 255, 255));
	draw_rect(p, get_tpoint(875, 74), get_tpoint(15, 15), get_color(0, 144, 0));
	draw_rect(p, get_tpoint(875, 98), get_tpoint(15, 15), get_color(255, 0, 0));
	draw_rect(p, get_tpoint(875, 122), get_tpoint(15, 15), get_color(31, 117, 254));
	draw_rect(p, get_tpoint(1050, 48), get_tpoint(15, 15), get_color(255, 255, 0));
	draw_rect(p, get_tpoint(1050, 74), get_tpoint(15, 15), get_color(255, 20, 147));
	draw_rect(p, get_tpoint(1050, 98), get_tpoint(15, 15), get_color(128, 128, 128));
}

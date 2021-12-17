/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:40:39 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/17 15:25:02 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/img.h"
#include "../../libft/libft.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		cur;

	if (x >= 1000 || x < 0 || y >= 1000 || y < 0)
		return ;
	cur = img->pbits - 8;
	pixel = img->buffer + (y * img->lbytes + x * (img->pbits / 8));
	while (cur >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> cur) & 0xFF;
		else
			*pixel++ = (color >> (img->pbits - 8 - cur)) & 0xFF;
		cur -= 8;
	}
}

void	img_init_background(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			img_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	clear_image(t_program *p)
{
	ft_bzero(p->img.buffer, p->width * p->height * (p->img.pbits / 8));
}

void	img_line_put(t_img *img, t_point p1, t_point p2, int color)
{
	double	dx;
	double	dy;
	int		pixels;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	double pixelX = p1.x;
	double pixelY = p1.y;
	while (pixels)
	{
		img_pixel_put(img, pixelX, pixelY, color);
		pixelX += dx;
		pixelY += dy;
		--pixels;
	}

	/*
	int d = p2.y / p2.x;
	int	S = 2 * d - 1;
	int Inc1 = 2 * d;
	int Inc2 = 2 * d - 2;
	int Y = 0;
	int X = 0;
	while (X < p2.x)
	{
		img_pixel_put(img, X, Y, color);
		if (S < 0)
			S = S + Inc1;
		else
		{
			S = S + Inc2;
			Y = Y + 1;
		}
	}
*/
/*
	double dx;
	double dy;
	int	e;

	double pixelX = p1.x;
	double pixelY = p1.y;
	e = p2.x - p1.x;
	dx = e * 2;
	dy = (p2.y - p1.y) * 2;
	while (pixelX <= p2.x)
	{
		img_pixel_put(img, pixelX, pixelY, color);
		pixelX++;

		if (e < 0)
			e = e + dx;
		else
		{
			e = e + dy;
			pixelY++;
		}


		if ((e = e - dy) <= 0)
		{
			pixelY++;
			e = e + dx;
		}

	}
*/
	/*
	int xH;
	int xB;
	xH = p1.x;
	xB = p2.x;
	if (p2.y <= p2.x)
	{
		xH = p2.x;
		xB = p1.x;
	}

	int	dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int dp = 2 * (dy - dx);
	int	deltaE = 2 * dy;
	int deltaNE = 2 * (dy - dx);
	if (xH >= xB)
	{
		dx = p1.x - p2.x;
		dy = p1.y - p2.y;
		if (dx >= dy)
		{
			dp = 2 * dy - dx;
			deltaE = 2 * dy;
			deltaNE = 2 * (dy - dx);
		}
		else
		{
			dp = 2 * dx - dy;
			deltaE = 2 * dx;
			deltaNE = 2 * (dx - dy);
		}
	}
	else
	{
		dx = p2.x - p1.x;
		dy = p1.y - p2.y;
		if (dx >= dy)
		{
			dp = 2 * dy - dx;
			deltaE = 2 * dy;
			deltaNE = 2 * (dy - dx);
		}
		else
		{
			dp = 2 * dx - dy;
			deltaE = 2 * dx;
			deltaNE = 2 * (dx - dy);
		}
	}
	int x = p1.x;
	int y = p1.y;
	img_pixel_put(img, x, y, color);
	while (x < p2.x)
	{
		if (dp <= 0)
		{
			if (xH >= xB)
				x++;
			else
				x--;
			y++;
			dp = dp + deltaE;
		}
		else
		{
			if (xH >= xB)
				x++;
			else
				x--;
			y++;
			dp = dp + deltaNE;
		}
		img_pixel_put(img, x, y, color);
	}
*/
}


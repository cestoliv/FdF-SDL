/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:27 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/17 15:29:21 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/img.h"

void	draw_map(t_point **map, t_img *img, int color)
{
	int	curx;
	int	cury;

	curx = 0;
	while (map[curx])
	{
		cury = 0;
		while (!map[curx][cury].last)
		{
			if (map[curx + 1])
				img_line_put(img, map[curx][cury], map[curx + 1][cury], color);
			if (!map[curx][cury + 1].last)
				img_line_put(img, map[curx][cury], map[curx][cury + 1], color);
			cury++;
		}
		curx++;
	}
}

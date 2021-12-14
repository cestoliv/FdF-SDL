/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:44:21 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/13 14:31:58 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	alloc_2dmap_array(t_point ***map, int height, int width)
{
	int	curh;
	int	curw;

	curh = 0;
	*map = (t_point **)malloc(sizeof(t_point *) * (height + 1));
	(*map)[height] = 0;
	while (curh < height)
	{
		(*map)[curh] = (t_point *)malloc(sizeof(t_point) * (width + 1));
		curw = 0;
		while (curw < width)
			(*map)[curh][curw++].last = 0;
		(*map)[curh][curw].last = 1;
		curh++;
	}
}

t_point	**convert_to_iso(t_3Dpoint **map)
{
	t_point		**isomap;
	int			curw;
	int			curh;
	t_3Dpoint	e;

	curh = 0;
	curw = 0;
	while (map[curh])
		curh++;
	while (!map[0][curw].last)
		curw++;
	alloc_2dmap_array(&isomap, curh, curw);
	curh = 0;
	while (isomap[curh])
	{
		curw = 0;
		while (!isomap[curh][curw].last)
		{
			e = map[curh][curw];
		
/*		
			isomap[curh][curw].x = (e.x - e.z) / sqrt(2) * 20;
			//isomap[curh][curw].x *= 20;
			isomap[curh][curw].x += 300;
			isomap[curh][curw].y = (e.x + 2 * e.y + e.z) / sqrt(6) * 20;
			//isomap[curh][curw].y *= 20;
			isomap[curh][curw].y += 50;
*/		

			/*
			isomap[curh][curw].x = (e.x - e.y) * 20 * 0.5;
			isomap[curh][curw].y = (e.x + e.y) * 20 * 1/sqrt(3) * 0.5;
			isomap[curh][curw].x += 300;
			isomap[curh][curw].y += 50;
			*/
/*	
			e.x *= 10;
			e.y *= 10;
			e.z *= 10;

			isomap[curh][curw].x = ((sqrt(2) / 2) * (e.x - e.y));
			//isomap[curh][curw].x *= 10;
			isomap[curh][curw].x += 300;
			isomap[curh][curw].y = ((sqrt(2/3) * e.z) - ((1 / sqrt(6)) * (e.x + e.y)));
			//isomap[curh][curw].y *= 10;
			isomap[curh][curw].y += 300;
*/
/*
			int w = (10 * sqrt(3)) / 2;
			isomap[curh][curw].x = -w * (e.z - e.x);
			isomap[curh][curw].y = -10 * (e.x / 2 + e.y + e.z / 2);
			isomap[curh][curw].x += 300;
			isomap[curh][curw].y += 300;
*/

			int x = e.x * 10;
			int y = e.y * 10;
			int z = e.z;

			isomap[curh][curw].x = (x - y) * cos(0.8);
			isomap[curh][curw].y = (x + y) * sin(0.8) - z;

			//isomap[curh][curw].x = x * 20 / (z / 10 + 1);
			//isomap[curh][curw].y = y * 20 / (z / 10 + 1);

			//isomap[curh][curw].x *= 10;
			//isomap[curh][curw].y *= 10;

			isomap[curh][curw].x += 300;
			isomap[curh][curw].y += 300;

			//isomap[curh][curw].x = isomap[curh][curw].x * cos(0.8) - isomap[curh][curw].y * sin(0.8);
			//isomap[curh][curw].y = isomap[curh][curw].y * cos(0.8) + isomap[curh][curw].x * sin(0.8);

			curw++;
		}
		curh++;
	}
	return (isomap);
}


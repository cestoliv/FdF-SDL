/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:44:21 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/15 11:00:55 by ocartier         ###   ########.fr       */
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

t_3Dpoint	pro_matmul(t_3Dpoint mul[2], t_3Dpoint mat)
{
	t_3Dpoint result;

	result.x = mat.x * mul[0].x + mat.y * mul[0].y + mat.z * mul[0].z;
	result.y = mat.x * mul[1].x + mat.y * mul[1].y + mat.z * mul[1].z;
	result.z = 0;
	return (result);
}

t_3Dpoint	rot_matmul(t_3Dpoint mul[3], t_3Dpoint mat)
{
	t_3Dpoint result;

	result.x = mat.x * mul[0].x + mat.y * mul[0].y + mat.z * mul[0].z;
	result.y = mat.x * mul[1].x + mat.y * mul[1].y + mat.z * mul[1].z;
	result.z = mat.x * mul[2].x + mat.y * mul[2].y + mat.z * mul[2].z;
	return (result);
}

t_point	**convert_to_iso(t_3Dpoint **map, t_map mapd)
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

			//double anglex = 0.7853982;
			double angley = 0;
			//double anglez = 0.6154729;

			int x = e.x * 10;
			int y = e.y * 10;
			int z = e.z;

			e.x *= 3;
			e.y *= 3;

			t_3Dpoint rotx[3];
			rotx[0].x = 1; rotx[0].y = 0; rotx[0].z = 0;
			rotx[1].x = 0; rotx[1].y = cos(mapd.rot_x); rotx[1].z = -sin(mapd.rot_x);
			rotx[2].x = 0; rotx[2].y = sin(mapd.rot_x); rotx[2].z = cos(mapd.rot_x);

			t_3Dpoint roty[3];
			roty[0].x = cos(angley); roty[0].y = 0; roty[0].z = sin(angley);
			roty[1].x = 0; roty[1].y = 1; roty[1].z = 0;
			roty[2].x = -sin(angley); roty[2].y = 0; roty[2].z = cos(angley);

			t_3Dpoint rotz[3];
			rotz[0].x = cos(mapd.rot_z); rotz[0].y = -sin(mapd.rot_z); rotz[0].z = 0;
			rotz[1].x = sin(mapd.rot_z); rotz[1].y = cos(mapd.rot_z); rotz[1].z = 0;
			rotz[2].x = 0; rotz[2].y = 0; rotz[2].z = 1;

			t_3Dpoint pro[2];
			pro[0].x = 1; pro[0].y = 0; pro[0].z = 0;
			pro[1].x = 0; pro[1].y = 1; pro[1].z = 0;

			t_3Dpoint rotated_y = rot_matmul(roty, e);
			t_3Dpoint rotated_x = rot_matmul(rotx, rotated_y);
			t_3Dpoint rotated_z = rot_matmul(rotz, rotated_x);
			/*
			printf("\nrot 1 / %f | %f | %f\n", rotz[0].x, rotz[0].y, rotz[0].z);
			printf("rot 2 / %f | %f | %f\n", rotz[1].x, rotz[1].y, rotz[1].z);
			printf("rot 3 / %f | %f | %f\n", rotz[2].x, rotz[2].y, rotz[2].z);
			printf("e / %f | %f | %f\n", e.x, e.y, e.z);
			printf("rot / %f | %f | %f\n", rotated_z.x, rotated_z.y, rotated_z.z);
			*/
			t_3Dpoint projected = pro_matmul(pro, rotated_z);

			isomap[curh][curw].x = projected.x;
			//isomap[curh][curw].x = (x - y) * cos(0.8);
			isomap[curh][curw].x *= mapd.zoom;

			isomap[curh][curw].y = projected.y;
			//isomap[curh][curw].y = (x + y) * sin(0.8) - z;
			isomap[curh][curw].y *= mapd.zoom;

			//isomap[curh][curw].x = x * 20 / (z / 10 + 1);
			//isomap[curh][curw].y = y * 20 / (z / 10 + 1);

			//isomap[curh][curw].x *= 10;
			//isomap[curh][curw].y *= 10;

			isomap[curh][curw].x += mapd.t_x;
			isomap[curh][curw].y += mapd.t_y;

			//isomap[curh][curw].x = isomap[curh][curw].x * cos(0.8) - isomap[curh][curw].y * sin(0.8);
			//isomap[curh][curw].y = isomap[curh][curw].y * cos(0.8) + isomap[curh][curw].x * sin(0.8);

			curw++;
		}
		curh++;
	}
	return (isomap);
}


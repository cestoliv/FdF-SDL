/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:41:06 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/09 10:07:09 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H
# include "fdf.h"
void	img_pixel_put(t_img *img, int x, int y, int color);
void	img_init_background(t_img *img, int width, int height, int color);
void	img_line_put(t_img *img, t_point p1, t_point p2, int color);
#endif

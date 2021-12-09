/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:02:48 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/09 10:37:08 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
typedef struct	s_img
{
	void	*img;
	int		pbits;
	int		lbytes;
	int		endian;
	char	*buffer;
}	t_img;

typedef struct	s_program
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_program;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;
#endif

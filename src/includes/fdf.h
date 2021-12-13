/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:02:48 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/13 12:54:15 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
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
	int	last;
}	t_point;

typedef struct	s_3Dpoint
{
	int	x;
	int	y;
	int	z;
	int	last;
}	t_3Dpoint;
#endif

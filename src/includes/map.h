/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:41:38 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/14 12:06:20 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

void	parse_map_file(char *filename, t_3Dpoint ***map);
t_point	**convert_to_iso(t_3Dpoint **map, t_map mapd);
#endif

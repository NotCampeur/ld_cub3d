/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_multithread_creators.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:50 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 10:03:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_multithread_struct	create_multithread_struct(t_player *p_hero,
							t_map *p_map, t_vector2 *p_lst)
{
	t_multithread_struct result;

	result.hero = p_hero;
	result.map = p_map;
	result.lst = p_lst;
	result.index = -1;
	result.num_pixel = -1;
	result.nb_to_draw = 0;
	return (result);
}

void					set_multithread_struct_value(t_multithread_struct *obj,
											int p_num_pixel, int p_nb_to_draw)
{
	obj->num_pixel = p_num_pixel;
	obj->nb_to_draw = p_nb_to_draw;
}

void					set_multithread_struct_index(t_multithread_struct *obj,
																	int p_index)
{
	obj->index = p_index;
}

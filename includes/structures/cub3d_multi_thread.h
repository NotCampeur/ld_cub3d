/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_multi_thread.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:15:11 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:50:44 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MULTI_THREAD_H
# define CUB3D_MULTI_THREAD_H

typedef struct			s_multithread_struct
{
	int					index;
	t_player			*hero;
	t_map				*map;
	t_vector2			*lst;
	int					num_pixel;
	int					nb_to_draw;
}						t_multithread_struct;

t_multithread_struct	create_multithread_struct(t_player *p_hero,
						t_map *p_map, t_vector2 *p_lst);

void					set_multithread_struct_value(t_multithread_struct *obj,
											int p_num_pixel, int p_nb_to_draw);
void					set_multithread_struct_index(t_multithread_struct *obj,
																int p_index);

void					destroy_multithread_struct(t_multithread_struct object);
void					free_multithread_struct(t_multithread_struct *object);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_calcul_h_infos.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:43:04 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 13:20:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CALCUL_H_INFOS_H
# define CUB3D_CALCUL_H_INFOS_H

typedef struct				s_calcul_h_data
{
	int						num_pixel;
	int						i;
	t_vector2				*lst;
	float					nb_to_draw;
	t_multithread_struct	object[NB_THREAD];
	void					*ptr[NB_THREAD][2];
	pthread_t				thread_list[NB_THREAD];
}							t_calcul_h_data;

#endif

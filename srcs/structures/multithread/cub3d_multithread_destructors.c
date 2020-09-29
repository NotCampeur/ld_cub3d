/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_multithread_destructors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:25:41 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 06:29:30 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void					destroy_multithread_struct(t_multithread_struct object)
{
	free_player(object.hero);
	free_map(object.map);
	free_vector2(object.lst);
}

void					free_multithread_struct(t_multithread_struct *object)
{
	destroy_multithread_struct(*object);
	free(object);
}

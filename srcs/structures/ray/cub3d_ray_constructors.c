/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_constructors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:10:04 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 10:12:21 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	create_ray(void)
{
	t_ray result;

	result.ray = create_vector2(0, 0);
	return (result);
}

t_ray	*malloc_ray(void)
{
	t_ray *result;

	result = (t_ray*)malloc(sizeof(t_ray));
	if (result == NULL)
		error_cub3d_exit(2);
	*result = create_ray();
	return (result);
}

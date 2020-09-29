/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_destructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:10:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 06:10:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_ray(t_ray p_ray)
{
	(void)p_ray;
}

void	free_ray(t_ray *p_ray)
{
	destroy_ray(*p_ray);
	free(p_ray);
}

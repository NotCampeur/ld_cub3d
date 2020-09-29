/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites_constructors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:30:07 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 15:09:49 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprites		create_sprites(t_ray p_ray, t_vector2 p_pos, char p_type)
{
	t_sprites result;

	result.ray = p_ray;
	result.pos = p_pos;
	result.type = p_type;
	return (result);
}

t_sprites		*malloc_sprites(t_ray p_ray, t_vector2 p_pos, char p_type)
{
	t_sprites *result;

	result = (t_sprites*)malloc(sizeof(t_sprites));
	if (result == NULL)
		error_cub3d_exit(2);
	*result = create_sprites(p_ray, p_pos, p_type);
	return (result);
}

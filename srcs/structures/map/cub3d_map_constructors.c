/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_constructors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:01:49 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 13:40:19 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	create_map(void)
{
	t_map result;

	result.resolution = create_vector2(0, 0);
	result.celling_tex = ft_strnew(0);
	result.floor_tex = ft_strnew(0);
	result.celling_color = create_color(0, 0, 0, 0);
	result.floor_color = create_color(0, 0, 0, 0);
	result.map = NULL;
	result.north = create_texture(NULL);
	result.south = create_texture(NULL);
	result.est = create_texture(NULL);
	result.west = create_texture(NULL);
	result.door = create_texture(NULL);
	result.sprite = create_texture(NULL);
	result.monster = create_monster(NULL, NULL, 0);
	result.medikit = create_medikit(NULL, 0);
	result.comp = ft_strdup("0DMmH2");
	result.valid = ft_strdup("12");
	result.size = create_vector2(0, 0);
	result.bonus = false;
	return (result);
}

t_map	*malloc_map(void)
{
	t_map *result;

	result = (t_map*)malloc(sizeof(t_map));
	if (result == NULL)
		error_cub3d_exit(5);
	*result = create_map();
	return (result);
}

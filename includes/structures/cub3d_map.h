/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:38:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 13:45:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

typedef struct	s_map
{
	t_vector2	resolution;

	t_texture	north;
	t_texture	south;
	t_texture	est;
	t_texture	west;
	t_texture	door;
	t_texture	sprite;
	t_monster	monster;
	t_medikit	medikit;

	char		*comp;
	char		*valid;

	char		*celling_tex;
	char		*floor_tex;

	t_color		celling_color;
	t_color		floor_color;

	char		**map;
	t_vector2	size;

	char		level;

	t_bool		bonus;
}				t_map;

t_map			create_map();
t_map			*malloc_map();
void			destroy_map(t_map p_map);
void			free_map(t_map *p_map);

#endif

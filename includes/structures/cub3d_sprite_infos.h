/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_infos.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:43:04 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 12:13:49 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_SPRITE_INFOS_H
# define CUB3D_SPRITE_INFOS_H

typedef struct	s_sprite_data
{
	t_texture	act;
	t_sprites	sprite;
	float		x;
	float		y;
	int			column;
	float		percent;
	int			num;
	int			i;
	t_vector2	pos;
	t_color		color;
	t_color		dark;
}				t_sprite_data;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:07:42 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/23 17:48:15 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

typedef struct	s_draw
{
	t_vector2	start;
	t_vector2	end;
	void		*info;
	t_map		map;
	float		alpha;
	t_player	hero;
}				t_draw;

t_draw			create_draw(t_map p_map, t_player p_hero, void *p_info,
																	int type);
void			detroy_draw(t_draw p_to_destroy);
void			set_draw_point(t_draw *p_to_set, float pixel_h, float pixel_b,
																float column);

#endif

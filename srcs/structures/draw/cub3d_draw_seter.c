/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_seter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:33:19 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 10:24:54 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_draw_point(t_draw *p_to_set, float pixel_h, float pixel_b,
																float column)
{
	p_to_set->start = create_vector2(column, pixel_h);
	p_to_set->end = create_vector2(column, pixel_b);
}

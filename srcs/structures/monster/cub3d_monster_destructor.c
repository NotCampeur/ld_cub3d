/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_monster_destructor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:12:58 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/27 15:15:03 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_monster(t_monster p_to_destroy)
{
	destroy_texture(p_to_destroy.life);
	destroy_texture(p_to_destroy.dead);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_monster_constructor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:04:23 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/27 15:15:31 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_monster	create_monster(char *p_life, char *p_dead, int p_dmg)
{
	t_monster result;

	result.life = create_texture(p_life);
	result.dead = create_texture(p_dead);
	result.damage = p_dmg;
	return (result);
}

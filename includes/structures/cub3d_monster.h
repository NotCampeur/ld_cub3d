/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_monster.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:50:54 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 11:37:38 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MONSTER_H
# define CUB3D_MONSTER_H

typedef struct	s_monster
{
	t_texture	life;
	t_texture	dead;
	int			damage;
}				t_monster;

t_monster		create_monster(char *p_life, char *p_dead, int p_dmg);
void			destroy_monster(t_monster p_to_destroy);
#endif

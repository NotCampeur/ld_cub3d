/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_constructors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:07:22 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/31 02:36:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	create_player(void)
{
	t_player result;

	result.pos = create_vector2(0, 0);
	result.move_speed = 0.2;
	result.rotation_speed = 0.15;
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	result.pitch = 0;
	result.radius = 0.2;
	result.size = 10;
	result.fov = 80;
	result.hp = 100;
	result.to_front = false;
	result.to_left = false;
	result.to_back = false;
	result.to_right = false;
	result.interact = false;
	result.interact_release = false;
	result.turn_right = false;
	result.turn_left = false;
	result.fire = false;
	return (result);
}

t_player	reset_player(int p_hp)
{
	t_player result;

	result.pos = create_vector2(0, 0);
	result.move_speed = 0.2;
	result.rotation_speed = 0.15;
	result.movement = create_vector2(0, 0);
	result.last_movement = create_vector2(0, 0);
	result.pitch = 0;
	result.radius = 0.2;
	result.size = 10;
	result.fov = 80;
	result.hp = p_hp;
	result.to_front = false;
	result.to_left = false;
	result.to_back = false;
	result.to_right = false;
	result.interact = false;
	result.interact = false;
	result.turn_right = false;
	result.turn_left = false;
	result.fire = false;
	return (result);
}

t_player	*malloc_player(void)
{
	t_player *result;

	result = (t_player*)malloc(sizeof(t_player));
	if (result == NULL)
		error_cub3d_exit(2);
	*result = create_player();
	return (result);
}

void		set_player_status(t_player *hero, t_map *map)
{
	(void)map;
	hero->size = 10;
	hero->radius *= hero->size;
	hero->pos.x = (hero->pos.x * hero->size) - (hero->size / 2);
	hero->pos.y = (hero->pos.y * hero->size) + (hero->size / 2);
}

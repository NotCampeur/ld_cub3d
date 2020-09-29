/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:13:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 18:01:36 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		update_player(t_map *map, t_player *hero)
{
	if (hero->hp > 0)
	{
		hero->movement = create_vector2(hero->forward.x - hero->pos.x,
				hero->forward.y - hero->pos.y);
		hero->last_movement = create_vector2(hero->movement.x * cos(PI / 2) -
			hero->movement.y * sin(PI / 2), hero->movement.x * sin(PI / 2) +
			hero->movement.y * cos(PI / 2));
		move_player(map, hero);
		interact(map, hero);
		rotate_player(hero);
		fire_player(map, hero);
		hero->hp = (hero->hp > 100) ? 100 : hero->hp;
	}
}

int			update(void *addr)
{
	t_player	*hero;
	t_map		*map;

	hero = (t_player*)(((void**)addr)[1]);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	map = (t_map*)(((void**)addr)[0]);
	update_player(map, hero);
	hero->forward = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
	hero->pos.x), ((-(int)(hero->size) + 1) * sin(hero->pitch) + hero->pos.y));
	clear_screen();
	if (map->bonus == true)
		draw_wall_multi_thread(*hero, map);
	else if (map->bonus == false)
		draw_wall(*hero, map);
	draw_gun(*map, hero);
	draw_hud(*map);
	draw_health_bar(*map, *hero);
	draw_2d_map(map, hero);
	if (hero->hp <= 0)
		draw_game_over(*map);
	render_screen();
	return (0);
}

static void	key_pressed_handler_two(int key, void *addr)
{
	t_map			*map;
	t_player		*hero;

	map = (t_map*)(((void**)addr)[0]);
	hero = (t_player*)(((void**)addr)[1]);
	if (key == NKMN_KEY && hero->hp > 0)
		hero->hp += -10;
	else if (key == NKPL_KEY && hero->hp > 0)
		hero->hp += 10;
	else if ((key == LSFT_KEY || key == RSFT_KEY) && hero->hp > 0)
		hero->fire = true;
	else if (key == RTN_KEY && hero->hp <= 0)
	{
		hero->hp = 100;
		load_map(map, hero);
	}
	else if (key == F_KEY && hero->interact_release == false)
	{
		hero->interact = true;
		hero->interact_release = true;
	}
}

int			key_pressed_handler(int key, void *addr)
{
	t_player		*hero;

	hero = (t_player*)(((void**)addr)[1]);
	if (key == ESC_KEY)
		error_cub3d_exit(0);
	else if (key == W_KEY)
		hero->to_front = true;
	else if (key == A_KEY)
		hero->to_left = true;
	else if (key == S_KEY)
		hero->to_back = true;
	else if (key == D_KEY)
		hero->to_right = true;
	else if (key == LEFT_KEY || key == Q_KEY)
		hero->turn_left = true;
	else if (key == RIGHT_KEY || key == E_KEY)
		hero->turn_right = true;
	else
		key_pressed_handler_two(key, addr);
	return (0);
}

int			key_released_handler(int key, void *addr)
{
	t_player		*hero;

	hero = (t_player*)(((void**)addr)[1]);
	if (key == W_KEY)
		hero->to_front = false;
	else if (key == A_KEY)
		hero->to_left = false;
	else if (key == S_KEY)
		hero->to_back = false;
	else if (key == D_KEY)
		hero->to_right = false;
	else if (key == LEFT_KEY || key == Q_KEY)
		hero->turn_left = false;
	else if (key == RIGHT_KEY || key == E_KEY)
		hero->turn_right = false;
	else if (key == LSFT_KEY || key == RSFT_KEY)
		hero->fire = false;
	else if (key == F_KEY)
		hero->interact_release = false;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mvt_behavior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:13:40 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/29 10:27:17 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			comp_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	is_practicable(t_player *h, t_vector2 mvt, t_map map, int sign)
{
	float	post_pos;
	float	last_pos;

	post_pos = h->pos.x + (mvt.x * h->move_speed * sign);
	last_pos = h->pos.x;
	if ((comp_char(map.comp, map.map[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos + h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((h->pos.y + h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((h->pos.y - h->radius) /
		(h->size))][(int)((post_pos - h->radius) / (h->size))])))
		h->pos.x += mvt.x * h->move_speed * sign;
	post_pos = h->pos.y + (mvt.y * h->move_speed * sign);
	if ((comp_char(map.comp, map.map[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos + h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((post_pos + h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))])) &&
		(comp_char(map.comp, map.map[(int)((post_pos - h->radius) /
		(h->size))][(int)((last_pos - h->radius) / (h->size))])))
		h->pos.y += mvt.y * h->move_speed * sign;
}

int			move_player(t_map *map, t_player *hero)
{
	int		update_state;

	update_state = 0;
	if (hero->to_front == true)
		is_practicable(hero, hero->movement, *map, 1);
	if (hero->to_left == true)
		is_practicable(hero, hero->last_movement, *map, -1);
	if (hero->to_back == true)
		is_practicable(hero, hero->movement, *map, -1);
	if (hero->to_right == true)
		is_practicable(hero, hero->last_movement, *map, 1);
	return (update_state);
}

int			rotate_player(t_player *hero)
{
	int		update_state;

	update_state = 0;
	if (hero->turn_right == true)
	{
		update_state = 1;
		hero->pitch -= hero->rotation_speed;
	}
	if (hero->turn_left == true)
	{
		update_state = 1;
		hero->pitch += hero->rotation_speed;
	}
	return (update_state);
}

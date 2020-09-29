/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_behavior.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:08:37 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 09:34:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	condition_interact(t_map *map, t_player *hero)
{
	if (map->map[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] == '3')
	{
		map->map[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] = 'D';
	}
	else if (map->map
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] == 'D'
		&& ((int)((hero->pos.y) / (hero->size)) != (int)((hero->pos.y +
		hero->movement.y) / (hero->size)) || (int)((hero->pos.x) /
		(hero->size)) != (int)((hero->pos.x + hero->movement.x) /
		(hero->size))))
	{
		map->map[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] = '3';
	}
	else if (map->map
		[(int)(hero->pos.y + hero->movement.y) / (int)(hero->size)]
		[(int)(hero->pos.x + hero->movement.x) / (int)(hero->size)] == '4')
	{
		map->level++;
		load_map(map, hero);
	}
	hero->interact = false;
}

void		interact(t_map *map, t_player *hero)
{
	if (hero->interact == true)
		condition_interact(map, hero);
	if (map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] == 'M')
	{
		hero->hp -= map->monster.damage;
		map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] = 'm';
	}
	if (map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] == 'H' && hero->hp < 100)
	{
		hero->hp += map->medikit.heal;
		map->map[(int)(hero->pos.y) / (int)(hero->size)]
		[(int)(hero->pos.x) / (int)(hero->size)] = '0';
	}
}

void		fire_player(t_map *map, t_player *hero)
{
	int	range;

	range = 1;
	if (hero->fire == true)
	{
		while (range <= 3)
		{
			if (map->map[(int)(hero->pos.y + (hero->movement.y * range)) /
			(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x * range)) /
			(int)(hero->size)] == 'M')
			{
				map->map[(int)(hero->pos.y + (hero->movement.y * range)) /
				(int)(hero->size)][(int)(hero->pos.x + (hero->movement.x *
				range)) / (int)(hero->size)] = 'm';
				break ;
			}
			else if (!(comp_char(map->comp, map->map[(int)(hero->pos.y +
				(hero->movement.y * range)) / (int)(hero->size)]
				[(int)(hero->pos.x + (hero->movement.x * range)) /
				(int)(hero->size)])))
				return ;
			range++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:08:37 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 11:39:52 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			condition5(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.map[y][x] == '2')
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, '2');
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else if (map.map[y][x] == '3')
		return (3);
	else if (map.map[y][x] == '4')
		return (4);
	return (0);
}

static int			condition4(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.map[y][x] == 'M')
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, 'M');
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition5(info, map, lst_sprite, hero));
	return (0);
}

static int			condition3(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.map[y][x] == 'H')
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, 'H');
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition4(info, map, lst_sprite, hero));
	return (0);
}

static int			condition2(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.map[y][x] == 'm')
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, 'm');
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition3(info, map, lst_sprite, hero));
	return (0);
}

int					type_condition(t_ray info, t_map map,
										t_sprites **lst_sprite, t_player hero)
{
	int			x;
	int			y;

	type_initializer(&x, &y, info, hero);
	if (map.map[y][x] == '1')
		return (1);
	else
		return (condition2(info, map, lst_sprite, hero));
	return (0);
}

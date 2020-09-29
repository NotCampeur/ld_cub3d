/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_behavior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:09:33 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 10:26:50 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_map(t_map *map, t_player *hero)
{
	char *arg;
	char num[2];

	*hero = reset_player(hero->hp);
	num[0] = map->level + 1;
	num[1] = '\0';
	write(1, "level :", 7);
	write(1, num, 1);
	write(1, "\n", 1);
	num[0] = map->level;
	arg = ft_strjoin("maps/start", num);
	arg = ft_strjoin(arg, ".cub");
	cub3d_get_param(map, arg);
	map->resolution = g_application->size;
	cub3d_parse_map(map, hero);
	hero->size = (int)((map->resolution.y * 0.33) / (map->size.y));
	if (hero->size > (int)((map->resolution.x * 0.27) / (map->size.x)))
		hero->size = (int)((map->resolution.x * 0.27) / (map->size.x));
	hero->radius *= hero->size;
	hero->pos.x = (hero->pos.x * hero->size) - (hero->size / 2);
	hero->pos.y = (hero->pos.y * hero->size) + (hero->size / 2);
}

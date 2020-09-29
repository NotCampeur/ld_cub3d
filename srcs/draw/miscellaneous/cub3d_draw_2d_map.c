/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_2d_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:04:33 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 18:08:54 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cropped_rectangle(t_vector2 info[3],
													t_map *map, t_color color)
{
	float i;
	float j;
	float range;

	i = 0;
	range = (map->resolution.x * 0.08);
	if (range > map->resolution.y * 0.08)
		range = map->resolution.y * 0.08;
	while (i < info[1].x)
	{
		j = 0;
		while (j < info[1].y)
		{
			if (vector2_distance(create_vector2(info[2].x, info[2].y),
					create_vector2(info[0].x + i, info[0].y + j)) < range)
				put_pixel(create_vector2(info[0].x + i, info[0].y + j), color);
			j++;
		}
		i++;
	}
}

void		put_square(t_map *map, t_vector2 info[3])
{
	t_vector2	pos;
	t_vector2	draw_info[3];

	pos = create_vector2(map->resolution.x * 0.155, map->resolution.y * 0.83);
	draw_info[0] = info[1];
	draw_info[1] = info[2];
	draw_info[2] = pos;
	if (map->map[(int)(info[0].y)][(int)(info[0].x)] == '1')
		draw_cropped_rectangle(draw_info, map, create_color(0, 0, 155, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == '2')
		draw_cropped_rectangle(draw_info, map, create_color(50, 220, 220, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == '0' ||
				map->map[(int)info[0].y][(int)(info[0].x)] == 'm')
		draw_cropped_rectangle(draw_info, map,
											create_color(255, 255, 255, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == '3' ||
		map->map[(int)info[0].y][(int)info[0].x] == 'D')
		draw_cropped_rectangle(draw_info, map,
											create_color(255, 155, 100, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == 'M')
		draw_cropped_rectangle(draw_info, map, create_color(150, 75, 150, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == 'H')
		draw_cropped_rectangle(draw_info, map, create_color(0, 255, 0, 255));
	else if (map->map[(int)info[0].y][(int)(info[0].x)] == '4')
		draw_cropped_rectangle(draw_info, map, create_color(255, 153, 0, 255));
}

static void	draw_player_n_forward(t_player *hero, int offset_x, int offset_y)
{
	t_vector2 line[2];

	line[0] = create_vector2(hero->pos.x + offset_x, hero->pos.y + offset_y);
	line[1] = create_vector2((((int)(hero->size) - 1) * cos(hero->pitch) +
		hero->pos.x + offset_x), ((-(int)(hero->size) + 1) * sin(hero->pitch) +
													(hero->pos.y + offset_y)));
	draw_circle(create_vector2(hero->pos.x + offset_x, hero->pos.y + offset_y),
			hero->radius * 2, create_color(255, 50, 50, 255));
	draw_line(line, create_color(0, 0, 0, 255), 2);
}

void		draw_2d_map(t_map *map, t_player *hero)
{
	t_vector2		info[3];
	int				offset_x;
	int				offset_y;

	offset_x = map->resolution.x * 0.155 - hero->pos.x;
	offset_y = map->resolution.y * 0.83 - hero->pos.y;
	info[0] = create_vector2(0, 0);
	info[1] = create_vector2(offset_x, offset_y);
	info[2] = create_vector2(hero->size - 1, hero->size - 1);
	while (map->map[(int)info[0].y])
	{
		info[0].x = 0;
		info[1].x = offset_x;
		while (map->map[(int)info[0].y][(int)info[0].x])
		{
			put_square(map, info);
			info[1].x = info[1].x + 1 + info[2].x;
			info[0].x++;
		}
		info[1].y = info[1].y + 1 + info[2].y;
		info[0].y++;
	}
	draw_player_n_forward(hero, offset_x, offset_y);
}

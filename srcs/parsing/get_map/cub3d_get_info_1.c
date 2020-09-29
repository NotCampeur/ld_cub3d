/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_get_info_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 18:12:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			get_info1(char *line, int j, int *ret, t_map *map)
{
	if (line[j] == 'R')
	{
		map->resolution = get_resolution(line + j);
		ret[1] = 1;
	}
	else if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (map->north.path != NULL)
			destroy_texture(map->north);
		j += 2;
		while (line[j] == ' ')
			j++;
		map->north = create_texture(ft_strdup(line + j));
		ret[2] = 1;
	}
	else if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (map->south.path != NULL)
			destroy_texture(map->south);
		j += 2;
		while (line[j] == ' ')
			j++;
		map->south = create_texture(ft_strdup(line + j));
		ret[3] = 1;
	}
}

void			get_info2(char *line, int j, int *ret, t_map *map)
{
	if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (map->west.path != NULL)
			destroy_texture(map->west);
		j += 2;
		while (line[j] == ' ')
			j++;
		map->west = create_texture(ft_strdup(line + j));
		ret[4] = 1;
	}
	else if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (map->est.path != NULL)
			destroy_texture(map->est);
		j += 2;
		while (line[j] == ' ')
			j++;
		map->est = create_texture(ft_strdup(line + j));
		ret[5] = 1;
	}
}

void			get_info3(char *line, int j, int *ret, t_map *map)
{
	int i;

	i = 0;
	if (line[j] == 'S' && line[j + 1] != 'O')
	{
		if (map->sprite.path != NULL)
			destroy_texture(map->sprite);
		j += 1;
		while (line[j] == ' ')
			j++;
		while (line[j + i] && line[j + i] != ' ')
			i++;
		line[j + i] = '\0';
		map->sprite = create_texture(ft_strdup(line + j));
		if (ft_atoi(line + j + i + 1) == 1)
			map->comp[5] = '\0';
		ret[6] = 1;
	}
	else if (line[j] == 'F')
	{
		map->floor_color = get_arg_color(line + j);
		ret[7] = 1;
	}
}

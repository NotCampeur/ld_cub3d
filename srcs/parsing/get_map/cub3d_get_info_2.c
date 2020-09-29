/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_get_info_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/31 02:44:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_int_len(int nbr)
{
	int		len;

	len = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

t_vector2		get_resolution(char *line)
{
	t_vector2	resolution;
	int			len;
	int			x_value;
	int			y_value;

	x_value = ft_atoi(line + 1);
	len = 1;
	while (line[2 + len] == ' ')
		len++;
	len += ft_int_len(x_value);
	y_value = ft_atoi(line + len + 1);
	y_value = (y_value > 1440) ? 1440 : y_value;
	y_value = (y_value < 1) ? 1 : y_value;
	x_value = (x_value > 2560) ? 2560 : x_value;
	x_value = (x_value < 1) ? 1 : x_value;
	resolution = create_vector2(x_value, y_value);
	return (resolution);
}

void			get_info4(char *line, int j, int *ret, t_map *map)
{
	int i;

	i = 0;
	if (line[j] == 'C')
	{
		map->celling_color = get_arg_color(line + j);
		ret[8] = 1;
	}
	else if (line[j] == 'H')
	{
		if (map->medikit.tex.path != NULL)
			destroy_medikit(map->medikit);
		j += 1;
		while (line[j] == ' ')
			j++;
		while (line[j + i] != ' ')
			i++;
		line[j + i] = '\0';
		map->medikit = create_medikit(ft_strdup(line + j),
													ft_atoi(line + j + i + 1));
		ft_str_add_suffix(&(map->valid), "H");
	}
}

void			get_info5(char *line, int j, t_map *map)
{
	int i;
	int d;

	i = 0;
	d = 0;
	if (line[j] == 'M')
	{
		if (map->monster.life.path != NULL || map->monster.dead.path != NULL)
			destroy_monster(map->monster);
		j += 1;
		while (line[j] == ' ')
			j++;
		while (line[j + i] != ' ')
			i++;
		while (line[j + i] == ' ')
			i++;
		line[j + i - 1] = '\0';
		while (line[j + i + d] != ' ')
			d++;
		line[j + i + d] = '\0';
		map->monster = create_monster(ft_strdup(line + j),
						ft_strdup(line + j + i), ft_atoi(line + j + i + d + 1));
		ft_str_add_suffix(&(map->valid), "M");
	}
}

void			get_info6(char *line, int j, t_map *map)
{
	char *setting;

	if (line[j] == 'D')
	{
		if (map->door.path != NULL)
			destroy_texture(map->door);
		j += 1;
		while (line[j] == ' ')
			j++;
		map->door = create_texture(ft_strdup(line + j));
		ft_str_add_suffix(&(map->valid), "3");
	}
	else if (line[j] == 'L')
	{
		j += 1;
		while (line[j] == ' ')
			j++;
		setting = ft_strdup(line + j);
		if (ft_strcmp(setting, "french") > 0)
			set_cub3d_langage(french);
		else if (ft_strcmp(setting, "english") > 0)
			set_cub3d_langage(english);
		else if (ft_strcmp(setting, "spanish") > 0)
			set_cub3d_langage(spanish);
	}
}

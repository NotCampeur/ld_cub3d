/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 08:32:09 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/12 16:46:22 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			loop_map(char *line, int *ret, t_map *map, int *i)
{
	int		j;

	j = 0;
	while (line[j] == ' ')
		j++;
	get_info1(line, j, ret, map);
	get_info2(line, j, ret, map);
	get_info3(line, j, ret, map);
	get_info4(line, j, ret, map);
	get_info5(line, j, map);
	get_info6(line, j, map);
	if (ret[9] == 1 && line[j] != '1')
		error_cub3d_exit(6);
	if (check_ret(ret) && line[j] == '1')
	{
		map->map = realloc_tab(map->map);
		map->map[*i] = line;
		(*i)++;
		ret[9] = 1;
	}
	else
		free(line);
}

void				cub3d_get_param(t_map *map, char *name)
{
	int		ret[10];
	int		fd;
	int		i;
	char	*line;

	set_ret(ret);
	check_multimap(map, name);
	fd = open(name, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
		error_cub3d_exit(6);
	i = 0;
	map->map = NULL;
	while ((ret[0] = get_next_line(fd, &line)) > 0)
		loop_map(line, ret, map, &i);
	if (check_ret(ret))
	{
		map->map = realloc_tab(map->map);
		map->map[i] = line;
	}
	else
		free(line);
	if (check_map(*map))
		error_cub3d_exit(8);
	close(fd);
}

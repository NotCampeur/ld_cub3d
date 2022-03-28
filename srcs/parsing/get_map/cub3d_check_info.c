/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:40:44 by ldutriez          #+#    #+#             */
/*   Updated: 2022/03/25 23:34:31 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_ret(int *ret)
{
	int i;

	i = 0;
	while (i < 10)
		ret[i++] = 0;
}

int			check_ret(int *ret)
{
	int i;

	i = 0;
	while (i < 9)
		if (ret[i++] != 1)
			return (0);
	return (1);
}

int			check_map(t_map map)
{
	if (map.resolution.x == 0 || map.resolution.y == 0 || map.north.path == NULL
		|| map.south.path == NULL || map.west.path == NULL ||
		map.est.path == NULL || map.sprite.path == NULL)
	{
		return (1);
	}
	return (0);
}

void		check_multimap(t_map *map, char *name)
{
	char	*mult;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mult = "start";
	while (name[j])
		j++;
	if (j < 10)
		return ;
	j -= 10;
	while (mult[i])
	{
		if (name[j] != mult[i])
			return ;
		j++;
		i++;
	}
	if (!(name[j] <= '9' && name[j] >= '0'))
		return ;
	ft_str_add_suffix(&(map->valid), "4");
	map->level = name[j];
}

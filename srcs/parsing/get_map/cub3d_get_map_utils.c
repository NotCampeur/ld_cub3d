/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_get_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:43:55 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/31 02:43:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**realloc_tab(char **map)
{
	int		i;
	char	**result;

	i = 0;
	if (map == NULL)
	{
		result = (char**)malloc(sizeof(char*) * 2);
		if (result == NULL)
			error_cub3d_exit(3);
		result[1] = NULL;
		return (result);
	}
	while (map && map[i] != NULL)
		i++;
	result = (char **)malloc(sizeof(char*) * (i + 2));
	if (result == NULL)
		error_cub3d_exit(3);
	result[i + 1] = NULL;
	i = -1;
	while (map[++i] != NULL)
		result[i] = map[i];
	free(map);
	return (result);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	str_is_digit(char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		if (is_digit(src[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_color_valid(char *line)
{
	char	**tab;
	char	**tmp;
	size_t	len;

	tab = ft_split(line, ' ');
	if (ft_tab_len(tab) != 2 || (tab[0][0] != 'F' && tab[0][0] != 'C'))
	{
		ft_tab_free(tab);
		return (0);
	}
	tmp = ft_split(tab[1], ',');
	ft_tab_free(tab);
	len = 0;
	while (tmp[len] != NULL)
	{
		if (str_is_digit(tmp[len]) == 0)
		{
			ft_tab_free(tmp);
			return (0);
		}
		len++;
	}
	ft_tab_free(tmp);
	return (1);
}

t_color		get_arg_color(char *line)
{
	char		**tab;
	char		**tmp;
	size_t		i;
	int			value[3];

	if (is_color_valid(line) == 0)
		error_cub3d_exit(6);
	tmp = ft_split(line, ' ');
	tab = ft_split(tmp[1], ',');
	i = 0;
	while (i < 3)
	{
		value[i] = ft_atoi(tab[i]);
		value[i] = (value[i] > 255) ? 255 : value[i];
		value[i] = (value[i] < 0) ? 0 : value[i];
		i++;
	}
	ft_tab_free(tmp);
	ft_tab_free(tab);
	return (create_color(value[0], value[1], value[2], 255));
}

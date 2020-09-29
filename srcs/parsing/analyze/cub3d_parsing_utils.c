/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:29:39 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/29 09:36:29 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern size_t	g_i;

void		first_last_line(t_map *param, t_parsing *info)
{
	char	*str;

	g_i = 0;
	if (param->map[info->nb])
	{
		info->size = ft_strlen_arg(param->map[info->nb], ' ');
		info->size = (param->size.x > info->size) ? param->size.x : info->size;
		if (!(str = malloc(sizeof(char) * (info->size + 1))))
			error_cub3d_exit(5);
		info->size = 0;
		while (param->map[info->nb][g_i])
		{
			if (param->map[info->nb][g_i] == '1')
				str[info->size++] = param->map[info->nb][g_i];
			else if (param->map[info->nb][g_i] != ' ')
				error_cub3d_exit(6);
			g_i++;
		}
		str[info->size] = '\0';
		info->before = info->size;
		free(param->map[info->nb]);
		param->map[info->nb] = str;
		info->nb++;
	}
}

static void	check_ultra_line(t_parsing info, t_map param)
{
	if (info.size < info.before)
	{
		info.size -= 1;
		while (param.map[info.nb - 1][info.size])
		{
			if (param.map[info.nb - 1][info.size] != '1')
				error_cub3d_exit(6);
			info.size++;
		}
	}
	if (info.size > info.before)
	{
		info.before -= 1;
		while (param.map[info.nb][info.before])
		{
			if (param.map[info.nb][info.before++] != '1')
				error_cub3d_exit(6);
			info.size++;
		}
	}
}

static void	save_hero_position(char c, int x, int y, t_player *hero)
{
	if (c == 'N')
		hero->pitch = PI / 2;
	else if (c == 'S')
		hero->pitch = -PI / 2;
	else if (c == 'E')
		hero->pitch = 0;
	else if (c == 'W')
		hero->pitch = PI;
	hero->pos.x = x;
	hero->pos.y = y;
}

static void	check_med(t_map *param, t_parsing *info, t_player *hero, char *str)
{
	if (param->map[info->nb][g_i] == '0')
	{
		info->error_full = false;
		str[info->size++] = param->map[info->nb][g_i];
	}
	else if (comp_char(param->valid, param->map[info->nb][g_i]))
		str[info->size++] = param->map[info->nb][g_i];
	else if (comp_char("NSEW", param->map[info->nb][g_i]))
	{
		info->error_full = false;
		info->error_multiplayer = info->error_player == 0 ? true : false;
		info->error_player = false;
		str[info->size++] = '0';
		save_hero_position(param->map[info->nb][g_i], info->size, info->nb,
																		hero);
	}
	else if (param->map[info->nb][g_i] != ' ')
		error_cub3d_exit(6);
	g_i++;
}

void		parsing_check(t_map *param, t_parsing *info, t_player *hero)
{
	char *str;

	info->size = ft_strlen_arg(param->map[info->nb], ' ');
	info->size = (param->size.x > info->size) ? param->size.x : info->size;
	if (!(str = malloc(sizeof(char) * (info->size + 1))))
		error_cub3d_exit(5);
	info->size = 0;
	g_i = 0;
	while (param->map[info->nb][g_i] == ' ')
		g_i++;
	if (param->map[info->nb][g_i] != '1')
		error_cub3d_exit(6);
	else
		str[info->size++] = param->map[info->nb][g_i++];
	while (param->map[info->nb][g_i])
		check_med(param, info, hero, str);
	str[info->size] = '\0';
	if (str[info->size - 1] != '1')
		error_cub3d_exit(6);
	free(param->map[info->nb]);
	param->map[info->nb] = str;
	check_ultra_line(*info, *param);
	info->nb++;
	info->before = info->size;
}

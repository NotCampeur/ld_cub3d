/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:14:56 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 09:35:22 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t			g_i;

void		cub3d_parse_map(t_map *param, t_player *hero)
{
	t_parsing	info;

	info = create_parsing();
	g_i = 0;
	first_last_line(param, &info);
	param->size.x = info.size;
	while (param->map[info.nb + 1] && param->map[info.nb])
	{
		parsing_check(param, &info, hero);
		param->size.x = (param->size.x < info.size) ? info.size : param->size.x;
	}
	first_last_line(param, &info);
	param->size.x = (param->size.x < info.size) ? info.size : param->size.x;
	param->size.y = info.nb;
	if (info.error_full)
		error_cub3d_exit(6);
	else if (info.error_player)
		error_cub3d_exit(6);
	else if (info.error_multiplayer)
		error_cub3d_exit(6);
}

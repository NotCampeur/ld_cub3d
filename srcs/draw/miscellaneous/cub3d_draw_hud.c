/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:53:17 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 14:50:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	select_pixel(t_image *img, int info[4], t_map map)
{
	if (img->pixels[info[3] + 2] != 0 ||
		img->pixels[info[3] + 1] != 0 ||
		img->pixels[info[3]] != 0)
	{
		put_pixel(create_vector2(info[0], info[1]),
		create_color(img->pixels[info[3] + 2],
					img->pixels[info[3] + 1],
					img->pixels[info[3]], 200));
	}
	info[3] = (int)((info[1] / map.resolution.y) * img->height) *
					img->width * (img->bits_per_pixel / 8) + info[2];
	info[1]++;
}

void		draw_hud(t_map map)
{
	static t_image	*img = NULL;
	int				info[4];

	if (img == NULL)
		img = malloc_image_from_file("textures/hud.xpm");
	info[0] = 0;
	info[1] = 0;
	while (info[0] < map.resolution.x)
	{
		info[2] = (int)((info[0] / map.resolution.x) * img->width) *
													(img->bits_per_pixel / 8);
		info[3] = info[2];
		while (info[1] < map.resolution.y)
		{
			select_pixel(img, info, map);
		}
		info[0]++;
		info[1] = 0;
	}
}

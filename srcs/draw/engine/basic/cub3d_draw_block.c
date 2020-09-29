/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:20:28 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 12:11:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		loop_draw_column(t_block_data b_inf, t_draw inf_draw)
{
	b_inf.x = b_inf.info.pos.x / inf_draw.hero.size;
	b_inf.y = b_inf.info.pos.y / inf_draw.hero.size;
	if (b_inf.info.fuck_float == 'x')
		b_inf.column = (int)((b_inf.y - (int)b_inf.y) * b_inf.act.width) *
												(b_inf.act.bits_per_pixel / 8);
	else
		b_inf.column = (int)((b_inf.x - (int)b_inf.x) * b_inf.act.width) *
												(b_inf.act.bits_per_pixel / 8);
	b_inf.num = 0;
	b_inf.i = b_inf.column;
	while (b_inf.num + inf_draw.start.y < inf_draw.end.y &&
		(inf_draw.end.y - b_inf.num >= 0 &&
		inf_draw.start.y + b_inf.num <= inf_draw.map.resolution.y))
	{
		b_inf.pos = create_vector2(inf_draw.start.x, inf_draw.start.y +
																	b_inf.num);
		b_inf.color = create_color(b_inf.act.tex[b_inf.i + 2],
			b_inf.act.tex[b_inf.i + 1], b_inf.act.tex[b_inf.i], inf_draw.alpha);
		put_pixel(b_inf.pos, b_inf.color);
		b_inf.num++;
		b_inf.i = ((int)((b_inf.num / (inf_draw.end.y - inf_draw.start.y)) *
				b_inf.act.height) * b_inf.act.width *
				(b_inf.act.bits_per_pixel / 8)) + b_inf.column;
	}
}

static void		its_a_wall(t_block_data *b_inf, t_draw inf_draw)
{
	if (b_inf->info.fuck_float == 'x')
	{
		if (b_inf->info.ray.x > 0)
			b_inf->act = inf_draw.map.west;
		else
			b_inf->act = inf_draw.map.est;
	}
	else
	{
		if (b_inf->info.ray.y > 0)
			b_inf->act = inf_draw.map.north;
		else
			b_inf->act = inf_draw.map.south;
	}
}

void			draw_column_block(t_draw inf_draw, int type)
{
	static t_texture	end;
	static int			first = 1;
	t_block_data		b_inf;

	b_inf.info = *(t_ray*)(inf_draw.info);
	if (first == 1)
	{
		end = create_texture("./textures/end.xpm");
		first = 0;
	}
	if (type == 1)
		its_a_wall(&b_inf, inf_draw);
	else if (type == 3)
		b_inf.act = inf_draw.map.door;
	else if (type == 4)
		b_inf.act = end;
	loop_draw_column(b_inf, inf_draw);
}

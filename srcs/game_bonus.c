/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:05:52 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 13:41:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		quit(void)
{
	error_cub3d_exit(0);
	return (0);
}

static void		check_arg(int argc, char *argv[], int *save)
{
	if (argc < 2 || argc > 4)
		error_cub3d_exit(4);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "-save") == true)
			*save = 1;
		else
			error_cub3d_exit(4);
	}
	if (ft_strstr(argv[1], ".cub") == 0)
		error_cub3d_exit(4);
}

static void		do_save(t_map *map, t_player *hero, int save)
{
	if (save == 1)
	{
		if (save_bmp(map, hero) == 0)
			error_cub3d_exit(9);
		error_cub3d_exit(0);
	}
}

int				main(int argc, char *argv[])
{
	void		*addr[2];
	t_player	*hero;
	t_map		*map;
	int			save;

	save = 0;
	set_cub3d_langage(french);
	check_arg(argc, argv, &save);
	open_application(create_vector2(840, 680), "Cub3D (c)");
	map = malloc_map();
	addr[0] = map;
	cub3d_get_param(map, argv[1]);
	resize_application(map->resolution);
	hero = malloc_player(create_vector2(36, map->resolution.y / 3));
	addr[1] = hero;
	cub3d_parse_map(map, hero);
	set_player_status(hero, map);
	map->bonus = true;
	do_save(map, hero, save);
	application_add_key_control(KEYRELEASE, &key_released_handler, &addr);
	application_add_key_control(KEYPRESS, &key_pressed_handler, &addr);
	application_add_exit_control(DESTROYNOTIFY, &quit);
	application_update(&update, &addr);
	run_application();
	return (0);
}

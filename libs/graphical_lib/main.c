/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:32:39 by ldutriez          #+#    #+#             */
/*   Updated: 2022/03/26 01:56:58 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"
#include <stdio.h>

int			key_pressed_handler(int key, void *addr)
{
	(void)addr;
	
	printf("key pressed: %d\n", key);
	if (key == ESC_KEY)
		error_exit(0);
	return (0);
}

static int		quit(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	open_application(create_vector2(840, 680), "Cub3D (c)");
	set_pixel(create_vector2(50, 50), create_color(255, 0, 0, 255));
	render_screen();
	application_add_key_control(KEYPRESS, KEYPRESSMASK, &key_pressed_handler, NULL);
	application_add_exit_control(DESTROYNOTIFY, &quit);
	run_application();
	return (0);
}

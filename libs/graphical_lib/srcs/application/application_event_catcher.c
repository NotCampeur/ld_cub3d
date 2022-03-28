/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_event_catcher.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:03:28 by ldutriez          #+#    #+#             */
/*   Updated: 2022/03/26 01:23:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lgl.h"

void			application_add_key_control(int event, int mask_event,
					int (*funct)(int, void *), void *param)
{
	mlx_hook(g_application->win_ptr, event, mask_event, funct, param);
}

void			application_add_mouse_control(
					int event, int (*funct)(int, void *), void *param)
{
	mlx_hook(g_application->win_ptr, event, 0L, funct, param);
}

void			application_add_exit_control(int event, int (*funct)(void))
{
	mlx_hook(g_application->win_ptr, event, 0L, funct, (void*)0);
}

void			application_update(int (*funct)(void *), void *param)
{
	mlx_loop_hook(g_application->mlx_ptr, funct, param);
}

void			run_application(void)
{
	mlx_loop(g_application->mlx_ptr);
}

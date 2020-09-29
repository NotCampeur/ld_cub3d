/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_destructors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:07:49 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 06:08:08 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_player(t_player p_player)
{
	(void)p_player;
}

void		free_player(t_player *p_player)
{
	destroy_player(*p_player);
	free(p_player);
}

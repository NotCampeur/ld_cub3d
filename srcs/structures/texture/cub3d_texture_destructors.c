/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture_destructors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:12:50 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/29 10:30:38 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_texture(t_texture p_wall)
{
	free(p_wall.path);
}

void	free_texture(t_texture *p_wall)
{
	destroy_texture(*p_wall);
	free(p_wall);
}

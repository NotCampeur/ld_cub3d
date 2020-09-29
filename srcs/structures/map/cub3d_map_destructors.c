/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_destructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:03:02 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/12 16:30:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map(t_map p_map)
{
	free(p_map.comp);
	free(p_map.valid);
	free(p_map.celling_tex);
	free(p_map.floor_tex);
	ft_tab_free(p_map.map);
}

void	free_map(t_map *p_map)
{
	destroy_map(*p_map);
	free(p_map);
}

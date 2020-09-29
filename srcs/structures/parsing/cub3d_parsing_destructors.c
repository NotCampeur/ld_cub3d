/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_destructors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:05:07 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 06:05:20 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_parsing(t_parsing p_parsing)
{
	(void)p_parsing;
}

void		free_parsing(t_parsing *p_parsing)
{
	destroy_parsing(*p_parsing);
	free(p_parsing);
}

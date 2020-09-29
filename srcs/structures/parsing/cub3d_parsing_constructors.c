/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing_constructors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:04:45 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/16 06:04:59 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	create_parsing(void)
{
	t_parsing result;

	result.nb = 0;
	result.size = 0;
	result.before = 0;
	result.error_full = true;
	result.error_player = true;
	result.error_multiplayer = false;
	return (result);
}

t_parsing	*malloc_parsing(void)
{
	t_parsing *result;

	result = (t_parsing*)malloc(sizeof(t_parsing));
	if (result == NULL)
		error_cub3d_exit(5);
	*result = create_parsing();
	return (result);
}

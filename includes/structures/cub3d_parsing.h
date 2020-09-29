/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:39:43 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/12 13:51:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

typedef struct	s_parsing
{
	size_t		nb;
	size_t		size;
	size_t		before;
	t_bool		error_multiplayer;
	t_bool		error_full;
	t_bool		error_player;
}				t_parsing;

t_parsing		create_parsing();
t_parsing		*malloc_parsing();
void			destroy_parsing(t_parsing p_parsing);
void			free_parsing(t_parsing *p_parsing);

#endif

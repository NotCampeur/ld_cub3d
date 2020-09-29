/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:15:43 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/23 17:52:37 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_SPRITES_H
# define CUB3D_SPRITES_H

typedef struct		s_sprites
{
	t_ray				ray;
	t_vector2			pos;
	char				type;
	struct s_sprites	*next;
}					t_sprites;

t_sprites			create_sprites(t_ray ray, t_vector2 pos, char p_type);
t_sprites			*malloc_sprites(t_ray ray, t_vector2 pos, char p_type);
void				destroy_sprites(t_sprites sprites);
void				free_sprites(t_sprites *sprites);
void				clear_sprites(t_sprites **sprites);

#endif

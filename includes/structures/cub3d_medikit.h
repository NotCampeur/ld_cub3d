/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_medikit.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:38:25 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 11:37:06 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MEDIKIT_H
# define CUB3D_MEDIKIT_H

typedef struct	s_medikit
{
	t_texture	tex;
	int			heal;
}				t_medikit;

t_medikit		create_medikit(char *p_tex, int p_heal);
void			destroy_medikit(t_medikit p_to_destroy);
#endif

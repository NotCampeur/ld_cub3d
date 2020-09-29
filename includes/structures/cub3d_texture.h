/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:19:33 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 11:38:34 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

typedef struct		s_wall
{
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*tex;
	char			*path;
}					t_texture;

t_texture			create_texture(char *path);
t_texture			*malloc_texture(char *path);
void				destroy_texture(t_texture p_wall);
void				free_texture(t_texture *p_wall);

#endif

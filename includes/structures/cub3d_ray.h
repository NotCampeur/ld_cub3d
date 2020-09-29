/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:19:33 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/29 19:18:30 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAY_H
# define CUB3D_RAY_H

typedef struct	s_ray
{
	t_vector2	rounded;
	t_vector2	pos;
	t_vector2	ray;
	float		angle;
	float		angle0;
	char		fuck_float;
	int			column;
}				t_ray;

t_ray			create_ray();
t_ray			*malloc_ray();
void			destroy_ray(t_ray p_ray);
void			free_ray(t_ray *p_ray);

#endif

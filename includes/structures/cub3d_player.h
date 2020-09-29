/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:20:07 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 09:34:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

typedef struct	s_player
{
	t_vector2	pos;

	float		move_speed;
	float		rotation_speed;

	t_vector2	movement;
	t_vector2	last_movement;

	t_vector2	forward;
	t_vector2	right;

	int			fov;
	float		pitch;

	float		radius;
	float		size;

	int			hp;

	t_bool		to_front;
	t_bool		to_left;
	t_bool		to_back;
	t_bool		to_right;

	t_bool		interact;
	t_bool		interact_release;

	t_bool		turn_right;
	t_bool		turn_left;

	t_bool		fire;
}				t_player;

t_player		create_player();
t_player		reset_player(int p_hp);
t_player		*malloc_player();
void			set_player_status(t_player *hero, t_map *map);

void			destroy_player(t_player p_player);
void			free_player(t_player *p_player);

int				rotate_player(t_player *hero);
int				move_player(t_map *map, t_player *hero);
void			interact(t_map *map, t_player *hero);
void			fire_player(t_map *map, t_player *hero);

void			load_map(t_map *map, t_player *hero);

#endif

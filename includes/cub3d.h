/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:24:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 11:33:31 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_includes.h"

void		cub3d_parse_map(t_map *param, t_player *hero);
void		first_last_line(t_map *param, t_parsing *info);
void		parsing_check(t_map *param, t_parsing *info, t_player *hero);

void		cub3d_get_param(t_map *map, char *name);
void		get_info1(char *line, int j, int *ret, t_map *map);
void		get_info2(char *line, int j, int *ret, t_map *map);
void		get_info3(char *line, int j, int *ret, t_map *map);
void		get_info4(char *line, int j, int *ret, t_map *map);
void		get_info5(char *line, int j, t_map *map);
void		get_info6(char *line, int j, t_map *map);
int			check_map(t_map map);
void		check_multimap(t_map *map, char *name);
char		**realloc_tab(char **map);
int			ft_int_len(int nbr);
t_vector2	get_resolution(char *line);
t_color		get_arg_color(char *line);
void		set_ret(int *ret);
int			check_ret(int *ret);

int			key_released_handler(int key, void *addr);
int			key_pressed_handler(int key, void *addr);
int			update(void *addr);
void		update_player(t_map *map, t_player *hero);

void		draw_wall(t_player hero, t_map *map);
void		type_initializer(int *x, int *y, t_ray info, t_player hero);
t_vector2	calc_inter(t_vector2 point1, t_vector2 direction1,
										t_vector2 point2, t_vector2 direction2);
int			type_condition(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero);
void		draw_column_block(t_draw inf_draw, int type);
void		draw_column_sprite(t_draw inf_draw);
void		draw_many_sprite(t_map map, t_sprites **lst_sprite,
													t_player hero, t_ray info);
void		test_check(t_ray *info, t_player hero, t_map map,
														t_sprites **lst_sprite);
void		check_ray(t_ray info, t_player hero,
											t_map map, t_sprites **lst_sprite);

void		draw_wall_multi_thread(t_player hero, t_map *map);

void		draw_2d_map(t_map *map, t_player *hero);
void		draw_hud(t_map map);
void		draw_gun(t_map map, t_player *hero);
void		draw_health_bar(t_map map, t_player hero);
void		draw_game_over(t_map map);

int			save_bmp();

int			comp_char(char *str, char c);

#endif

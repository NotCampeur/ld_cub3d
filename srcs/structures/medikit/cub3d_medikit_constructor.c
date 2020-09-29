/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_medikit_constructor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:42:53 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/28 13:52:09 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_medikit	create_medikit(char *p_tex, int p_heal)
{
	t_medikit	result;

	result.tex = create_texture(p_tex);
	result.heal = p_heal;
	return (result);
}

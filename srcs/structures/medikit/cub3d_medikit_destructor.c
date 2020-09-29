/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_medikit_destructor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:44:31 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/28 13:45:05 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_medikit(t_medikit p_to_destroy)
{
	destroy_texture(p_to_destroy.tex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites_destructors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:45:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/29 10:27:43 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			destroy_sprites(t_sprites sprites)
{
	(void)sprites;
}

void			free_sprites(t_sprites *sprites)
{
	destroy_sprites(*sprites);
	free(sprites);
}

void			clear_sprites(t_sprites **sprites)
{
	t_sprites *lst;

	if (*sprites == NULL)
		return ;
	while (*sprites)
	{
		lst = *sprites;
		*sprites = lst->next;
		free(lst);
	}
	lst = NULL;
	sprites = NULL;
}

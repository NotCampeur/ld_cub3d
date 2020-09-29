/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:48:13 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/30 18:36:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_langage g_cub3d_langage;

char *g_error_cub3d_msg[][3] = {
	{
		"Program close successfully",
		"Le programme s'est arrete correctement",
		"Programa cerrado exitosamente"
	},
	{
		"Error",
		"Erreur",
		"Error"
	},
	{
		"Can't malloc a Player",
		"Echec du malloc d'un joueur",
		"No puedo malloc un jugador"
	},
	{
		"Can't malloc a line in GNL",
		"Echec du malloc d'une ligne dans gnl",
		"No puedo malloc una línea en GNL"
	},
	{
		"Wrong arguments",
		"Arguments erronés",
		"Argumentos equivocados"
	},
	{
		"Can't malloc on map parsing",
		"Echec du malloc dans le parsing de la map",
		"No se puede malloc en el análisis del mapa"
	},
	{
		"Invalid map",
		"Carte invalide",
		"Mapa inválido"
	},
	{
		"You suck, you got lost!",
		"T'es nul, t'as perdu!",
		"¡Apestas, te perdiste!"
	},
	{
		"Invalid File",
		"Fichier non valide",
		"Archivo inválido"
	},
	{
		"Save error",
		"Erreur de sauvegarde",
		"Guardar error"
	}
};

void		set_cub3d_langage(t_langage p_langage)
{
	g_cub3d_langage = p_langage;
}

static void	good_cub3d_exit(int msg)
{
	lgl_putstr(g_error_cub3d_msg[msg][(int)g_cub3d_langage]);
	lgl_putchar('\n');
	exit(0);
}

void		error_cub3d_exit(int error)
{
	if (error == 0 || error == 7)
		good_cub3d_exit(error);
	lgl_putstr(g_error_cub3d_msg[1][(int)g_cub3d_langage]);
	lgl_putstr(" [");
	lgl_putnbr(error);
	lgl_putstr("] : ");
	lgl_putstr(g_error_cub3d_msg[error][(int)g_cub3d_langage]);
	lgl_putchar('\n');
	exit(error);
}

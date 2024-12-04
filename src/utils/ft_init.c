/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:46:57 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 13:43:58 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h" 

/**
 * @brief Initialise les données de la structure t_data.
 *
 * Cette fonction met à zéro les pointeurs de l'image, de la fenêtre, 
 * de la connexion à la bibliothèque MLX, et de la carte dans la 
 * structure t_data. Elle est généralement appelée au début du 
 * programme pour préparer l'utilisation de ces éléments.
 *
 * @param f Pointeur vers la structure t_data à initialiser.
 */
static void	init_data(t_data *f)
{
	f->img = NULL;
	f->mlx = NULL;
	f->win = NULL;
	f->map = NULL;
	f->fic = NULL;
	f->addr = NULL;
}

static void	init_key(t_data *f)
{
	f->keyb.dow = 0;
	f->keyb.up = 0;
	f->keyb.lf = 0;		
	f->keyb.lr = 0;
	f->keyb.is_azerty = ISAZERTY;
	f->keyb.is_press = 0;
}

static void	init_user(t_data *f)
{
	f->userd.coox = 0;
	f->userd.cooy = 0;
	f->userd.dir = 270;
}

/*
t_data	*init_struct(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(data));
	if (!data)
		ft_exit_error(E_MALLOC, NULL);
	data->keyb.is_azerty = ISAZERTY;
	data->userd.dir = 270;
	return (data);
}*/

void	init_struct(t_data *f)
{

	init_data(f);
	init_key(f);
	init_user(f);
}
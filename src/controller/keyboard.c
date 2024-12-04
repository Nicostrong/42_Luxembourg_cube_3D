/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:48:42 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 10:46:29 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h" 

/**
 * @brief Déplace l'utilisateur verticalement en fonction des touches.
 * 
 * Cette fonction ajuste `f->userd.cooy` vers le haut si `f->keyb.up` 
 * est activé et vers le bas si `f->keyb.dow` est activé. Les mouvements 
 * sont limités par `f->xmap` pour éviter les débordements de la carte.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 */
static void	vert_move(t_data *f)
{
	if (f->keyb.dow && f->userd.coox < f->xmap - 1)
		if(f->map[f->userd.coox + 1][f->userd.cooy] != '1')
			f->userd.coox++;
	if (f->keyb.up && f->userd.coox > 0)
		if(f->map[f->userd.coox - 1][f->userd.cooy] != '1')
			f->userd.coox--;
}

/**
 * @brief Déplace l'utilisateur horizontalement en fonction des touches.
 * 
 * Cette fonction déplace `f->userd.coox` vers la droite si `f->keyb.lr`
 * est activé, et vers la gauche si `f->keyb.lf` est activé. Les mouvements
 * sont limités par `f->ymap` pour éviter les débordements de la carte.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 */
static void	hori_move(t_data *f)
{
	if (f->keyb.lr && f->userd.cooy < f->ymap - 2)
		if(f->map[f->userd.coox][f->userd.cooy + 1] != '1')
			f->userd.cooy++;
	if (f->keyb.lf && f->userd.cooy > 0)
		if(f->map[f->userd.coox][f->userd.cooy - 1] != '1')
			f->userd.cooy--;
}

/**
 * @brief Gère la pression d'une touche et met à jour l'état de pression.
 * 
 * @param keysym Code de la touche appuyée.
 * @param f Structure des données contenant les états et paramètres de 
 * l'affichage.
 * @return Toujours 0.
 */
int	pr_key(int keysym, t_data *f)
{
	if (f->keyb.is_azerty == 0)
		pr_key_wasd(keysym, f);
	else if (f->keyb.is_azerty == 1)
		pr_key_zqsd(keysym, f);
	f->keyb.is_press = 1;
	return (0);
}

/**
 * @brief Gère le relâchement d'une touche et met à jour l'état de pression.
 * 
 * @param keysym Code de la touche relâchée.
 * @param f Structure des données contenant les états et paramètres de 
 * l'affichage.
 * @return Toujours 0.
 */
int	rl_key(int keysym, t_data *f)
{
	if (f->keyb.is_azerty == 0)
		rl_key_wasd(keysym, f);
	else if (f->keyb.is_azerty == 1)
		rl_key_zqsd(keysym, f);
	f->keyb.is_press = 0;
	return (0);
}

/**
 * @brief Met à jour les déplacements selon les touches pressées et rafraîchit.
 * 
 * @param f Structure des données contenant l'état des touches et le temps.
 * @return Toujours 0.
 */
int	update_key(t_data *f)
{
	long time;

	time = ft_get_time_ms();
	if(time - f->lastfram >= FRAMT)
	{
		if (f->keyb.dow || f->keyb.up)
			vert_move(f);
		if (f->keyb.lf || f->keyb.lr)
			hori_move(f);
		ft_rendermap(f);
		//ft_render(f);
		f->lastfram = time;
		aff_map_ctr(f); //DEBUG
	}
	return (0);
}
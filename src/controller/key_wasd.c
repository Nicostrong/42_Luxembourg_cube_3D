/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_wasd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:48:42 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/31 09:57:37 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h" 

/**
 * @brief Assigne l'état des touches WASD selon l'entrée clavier reçue.
 * 
 * @param keysym Code de la touche appuyée.
 * @param f Structure des données contenant les états du clavier et l'affichage.
 * @return Toujours 0.
 */
int	pr_key_wasd(int keysym, t_data *f)
{
	if (keysym == XK_Escape)
		ft_close(f);
	else if (keysym == XK_e)
		printf("use\n");
	else if (keysym == XK_Up || keysym == XK_w)
		f->keyb.up = 1;
	else if (keysym == XK_Down || keysym == XK_s)
		f->keyb.dow = 1;
	else if (keysym == XK_Left || keysym == XK_a)
		f->keyb.lf = 1;
	else if (keysym == XK_Right || keysym == XK_d)
		f->keyb.lr = 1;
	else if (keysym == XK_space)
		printf("jump\n");
	return (0);
}

/**
 * @brief Réinitialise l'état des touches WASD selon l'entrée clavier reçue.
 * 
 * @param keysym Code de la touche relâchée.
 * @param f Structure des données contenant les états du clavier et l'affichage.
 * @return Toujours 0.
 */
int	rl_key_wasd(int keysym, t_data *f)
{
	if (keysym == XK_Up || keysym == XK_w)
		f->keyb.up = 0;
	else if (keysym == XK_Down || keysym == XK_s)
		f->keyb.dow = 0;
	else if (keysym == XK_Left || keysym == XK_a)
		f->keyb.lf = 0;
	else if (keysym == XK_Right || keysym == XK_d)
		f->keyb.lr = 0;
	return (0);
}

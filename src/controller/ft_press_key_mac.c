/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:28:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/21 17:41:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_press_key_mac(int keysym, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_press_key_mac manage the key pressed by the user on Mac.
 * </description>
 *
 * <param type="int" name="keysym">key pressed</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit code 0.
 * </return>
 *
 */
int	ft_press_key_mac(int keysym, t_info *info)
{
	printf("\t\t\tKeysym = %d\n", keysym);
	if (keysym == ESCAP)
		ft_exit(info);
	else if (keysym == KZ || keysym == UP)
		ft_move(info, 0, 1);
	else if (keysym == KS || keysym == DOWN)
		ft_move(info, 0, -1);
	else if (keysym == KQ)
		ft_move(info, -M_PI_2, 1);
	else if (keysym == KD)
		ft_move(info, M_PI_2, 1);
	else if (keysym == KA || keysym == LEFT)
		info->user_deg -= ROTATE;
	else if (keysym == KE || keysym == RIGHT)
		info->user_deg += ROTATE;
	info->user_deg = ft_normalize_rot(info->user_deg);
	if (BONUS)
	{
		if (keysym == SPACE)
			ft_open_door(info);
		ft_minimap(info);
	}
	ft_raycasting(info);
	return (0);
}

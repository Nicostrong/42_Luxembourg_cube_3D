/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 13:29:37 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/minimap.h"
#include "../../includes/structures.h"

/*
 *	il faut lire data.
 *	pour chaque ligne longue de line_size
 *	si le pixel alpha est 'FF' on passe au suivant
 */
void	ft_put_player(t_info *info, t_img *player, int x, int y)
{
	int			index;
	int			line;
	int			mini_x;
	int			mini_y;
	uint32_t	*player_data;
	uint32_t	*mini_data;
	uint32_t	pixel;

	player_data = (uint32_t *)player->addr;
	mini_data = (uint32_t *)info->mini->addr;
	line = -1;
	while (++line < MINI_S_PL)
	{
		index = -1;
		while (++index < MINI_S_PL)
		{
			pixel = player_data[line * MINI_S_PL + index];
			if (pixel != 0xFF000000)
			{
				mini_x = x - (MINI_S_PL / 2) + index;
				mini_y = y - (MINI_S_PL / 2) + line;
				mini_data[mini_y * (info->mini->size / 4) + mini_x] = pixel;
			}
		}
	}
}
	/*if (player)
		mlx_put_image_to_window(info->mlx, info->mini->win, player->img, \
				x - 5, y - 5);
	else
		ft_put_circle(info, x, y);
	return ;
}*/

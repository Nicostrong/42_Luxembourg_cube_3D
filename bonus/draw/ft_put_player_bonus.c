/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/06 07:26:33 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

void	ft_put_player(t_info *info, t_img *player, int x, int y)
{
	if (player && player->addr)
	{
		ft_put_imgalpha(info->mini, info->player, x - (info->player->w / 2), \
			y - (info->player->h / 2));
		mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, \
			0, 0);
	}
	else
		ft_put_circle(info, x, y);
	return ;
}

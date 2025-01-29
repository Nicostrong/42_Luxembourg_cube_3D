/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/29 09:53:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

void	ft_put_door(t_info *info, int x, int y)
{
	int bar_thickness = 5; // Épaisseur de la barre
	int color = (unsigned int)DOOR;

	// Si la porte est horizontale
	if (x > 0 && map[y][x - 1] == map[y][x])
		ft_put_rect(info, x * cell_width, y * cell_height + (cell_height / 2 - bar_thickness / 2), cell_width, bar_thickness, color);
	else
		ft_put_rect(info, x * cell_width + (cell_width / 2 - bar_thickness / 2), y * cell_height, bar_thickness, cell_height, color);
}
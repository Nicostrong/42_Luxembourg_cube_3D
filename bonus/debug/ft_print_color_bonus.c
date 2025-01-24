/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:34:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 08:00:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_color(t_color *color)
 * </summary>
 *
 * <description>
 * 	ft_print_color print all information about a color structure.
 * </description>
 *
 * <param type="t_color *" name="color">structure color</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_color(t_color *color)
{
	printf("\tt: %d\n", color->t);
	printf("\tr: %d\n", color->r);
	printf("\tg: %d\n", color->g);
	printf("\tb: %d\n", color->b);
	printf("\tcolor: %x\n", color->color);
	return ;
}

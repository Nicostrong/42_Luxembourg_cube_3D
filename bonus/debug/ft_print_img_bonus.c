/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/04 08:57:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_img(t_img *img)
 * </summary>
 *
 * <description>
 * 	ft_print_img print all information about an image structure.
 * </description>
 *
 * <param type="t_img *" name="img">image structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_img(t_img *img)
{
	printf("\tpath: %s\n", img->img_path);
	printf("\th: %d\n", img->h);
	printf("\tw: %d\n", img->w);
	printf("\tsize: %d\n", img->size);
	printf("\tBPP: %d\n", img->bpp);
	printf("\timg: %p\n", img->img);
	printf("\taddr: %p\n", img->addr);
	return ;
}

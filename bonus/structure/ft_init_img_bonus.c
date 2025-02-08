/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:50:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 15:38:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_img(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_img initialise all img structure.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_init_img(t_info *info)
{
	info->s_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->s_img)
		ft_perror_exit(E_MALLOC, info);
	info->f_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->f_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_n_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_n_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_e_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_e_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_s_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_s_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_w_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_w_img)
		ft_perror_exit(E_MALLOC, info);
	info->player = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->player)
		ft_perror_exit(E_MALLOC, info);
	info->door = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->door)
		ft_perror_exit(E_MALLOC, info);
	return ;
}

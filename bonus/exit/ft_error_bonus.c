/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:32:13 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 15:38:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_error_msg(int value, int exit, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_error_msg print all error messages on stderror and exit if exit is true.
 * 	The value is a binary value to select all individual message error to print.
 * </description>
 *
 * <param type="int" name="value">value for error message</param>
 * <param type="int" name="exit">bool value for exit</param>
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_error_msg(int value, int exit, t_info *info)
{
	if (value & W_N_IMG_E)
		ft_putendl_fd(E_NOT, 2);
	if (value & W_S_IMG_E)
		ft_putendl_fd(E_SOT, 2);
	if (value & W_E_IMG_E)
		ft_putendl_fd(E_EAT, 2);
	if (value & W_W_IMG_E)
		ft_putendl_fd(E_WET, 2);
	if (value & E_COL_S)
		ft_putendl_fd(E_C, 2);
	if (value & E_COL_F)
		ft_putendl_fd(E_F, 2);
	if (value & P_IMG_E)
		ft_putendl_fd(E_P, 2);
	if (value & D_IMG_E)
		ft_putendl_fd(E_D, 2);
	if (exit)
		ft_perror_exit(NULL, info);
	return ;
}

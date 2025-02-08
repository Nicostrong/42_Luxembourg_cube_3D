/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_thread_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:26:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 14:24:43 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_thread(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_thread print all data of the thread structure.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_thread(t_info *info)
{
	printf("******************************\n");
	printf(BBLUE"\tTHREAD STRUCTURE\n"RESET);
	printf("******************************\n");
	if (!info->thread)
	{
		printf(REDC"\tthread is NULL\n"RESET);
		return ;
	}
	printf("pointer of thread for minimap : %p\n", &info->thread->t_mini);
	printf("pointer of thread for game : %p\n", &info->thread->t_game);
	printf("pointer of mutex for map : %p\n", &info->thread->m_map);
	printf("pointer of mutex for user_x : %p\n", &info->thread->m_user_x);
	printf("pointer of mutex for user_y : %p\n", &info->thread->m_user_y);
	printf("pointer of mutex for user_d : %p\n", &info->thread->m_user_d);
	printf("pointer of mutex for stop : %p\n", &info->thread->m_stop);
	return ;
}

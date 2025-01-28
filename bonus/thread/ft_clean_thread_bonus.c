/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_thread_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:00:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/28 10:08:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	void	ft_clean_thread_mutex(t_thread **thread)
 * </summary>
 *
 * <description>
 * 	ft_clean_thread_mutex destroy all mutex.
 * </description>
 *
 * <param type="t_thread **" name="thread">thread structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_clean_thread_mutex(t_thread **thread)
{
	if ((*thread)->mut_map)
		pthread_mutex_destroy(&(*thread)->m_map);
	if ((*thread)->mut_x)
		pthread_mutex_destroy(&(*thread)->m_x);
	if ((*thread)->mut_y)
		pthread_mutex_destroy(&(*thread)->m_y);
	if ((*thread)->mut_user_x)
		pthread_mutex_destroy(&(*thread)->m_user_x);
	if ((*thread)->mut_user_y)
		pthread_mutex_destroy(&(*thread)->m_user_y);
	if ((*thread)->mut_user_d)
		pthread_mutex_destroy(&(*thread)->m_user_d);
	if ((*thread)->mut_stop)
		pthread_mutex_destroy(&(*thread)->m_stop);
	ft_free((void **)thread);
	return ;
}

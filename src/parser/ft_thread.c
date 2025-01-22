/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:02:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/22 14:57:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/error.h"
#include "../../includes/minimap.h"
#include "../../includes/raycasting.h"

void	ft_run_mini(t_info *info)
{
	pthread_mutex_lock(info->thread->m_stop);
	while (!info->stop)
	{
		pthread_mutex_unlock(info->thread->m_stop);
		ft_minimap(info);
		pthread_mutex_lock(info->thread->m_stop);
	}
	pthread_mutex_unlock(info->thread->m_stop);
}

void	ft_run_raycast(t_info *info)
{
	pthread_mutex_lock(info->thread->m_stop);
	while (!info->stop)
	{
		pthread_mutex_unlock(info->thread->m_stop);
		ft_raycasting(info);
		pthread_mutex_lock(info->thread->m_stop);
	}
	pthread_mutex_unlock(info->thread->m_stop);
}

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	void	ft_init_thread(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_thread initialise each thread of philosopher.
 * 	execute each thread with the runtime and wait the end of each thread.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * 
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_init_thread(t_info *info)
{
	int	ret;

	ret = 0;
	ret = pthread_create(&info->thread->t_mini, NULL, &ft_run_mini, info);
	if (ret)
		ft_perror_exit(E_THREAD, info);
	ret = pthread_create(&info->thread->t_game, NULL, &ft_run_raycast, info);
	if (ret)
		ft_perror_exit(E_THREAD, info);
	ret = pthread_join(info->thread->t_mini, NULL);
	if (ret)
		ft_perror_exit(E_JOIN_TH, info);
	ret = pthread_join(info->thread->t_game, NULL);
	if (ret)
		ft_perror_exit(E_JOIN_TH, info);
}

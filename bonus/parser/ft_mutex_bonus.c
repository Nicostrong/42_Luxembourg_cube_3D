/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:53:58 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 09:13:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/structures.h"
#include "../../includes/error.h"

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	int	ft_init_mutex(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_mutex initialise all global mutex on the struct info.
 * </description>
 *
 * <param type="t_info *" name="info">info structure</param>
 *
 * <return>
 * 	1 if all right or exit faillure.
 * </return>
 *
 */

int	ft_init_mutex(t_info *info)
{
	if (pthread_mutex_init(&info->thread->m_map, NULL))
		return (ft_perror_exit(E_MUTEX, info));
	if (pthread_mutex_init(&info->thread->m_user_d, NULL))
	{
		pthread_mutex_destroy(&info->thread->m_map);
		return (ft_perror_exit(E_MUTEX, info));
	}
	if (pthread_mutex_init(&info->thread->m_user_x, NULL))
	{
		pthread_mutex_destroy(&info->thread->m_map);
		pthread_mutex_destroy(&info->thread->m_user_d);
		return (ft_perror_exit(E_MUTEX, info));
	}
	if (pthread_mutex_init(&info->thread->m_user_y, NULL))
	{
		pthread_mutex_destroy(&info->thread->m_map);
		pthread_mutex_destroy(&info->thread->m_user_d);
		pthread_mutex_destroy(&info->thread->m_user_x);
		return (ft_perror_exit(E_MUTEX, info));
	}
	if (pthread_mutex_init(&info->thread->m_stop, NULL))
	{
		pthread_mutex_destroy(&info->thread->m_map);
		pthread_mutex_destroy(&info->thread->m_user_d);
		pthread_mutex_destroy(&info->thread->m_user_x);
		pthread_mutex_destroy(&info->thread->m_user_y);
		return (ft_perror_exit(E_MUTEX, info));
	}
	return (1);
}

/*
 * <cat>philosopher</cat>
 *
 * <summary>
 * 	void	ft_clean_thread_mutex(t_data *data)
 * </summary>
 *
 * <description>
 * 	ft_clean_thread_mutex destroy all mutex on the thread philo.
 * </description>
 *
 * <param type="t_data *" name="data">data structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_clean_thread_mutex(t_info *info)
{
	pthread_mutex_destroy(&info->thread->m_map);
	pthread_mutex_destroy(&info->thread->m_user_d);
	pthread_mutex_destroy(&info->thread->m_user_x);
	pthread_mutex_destroy(&info->thread->m_user_y);
	pthread_mutex_destroy(&info->thread->m_stop);
}

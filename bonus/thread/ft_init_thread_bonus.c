/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:02:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 13:00:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	void	ft_init_mutex(t_info *info, t_thread *thread)
 * </summary>
 *
 * <description>
 * 	ft_init_mutex initialise all global mutex on the struct info.
 * </description>
 *
 * <param type="t_info *" name="info">info structure</param>
 * <param type="t_thread *" name="thread">thread structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_init_mutex(t_info *info, t_thread *thread)
{
	if (pthread_mutex_init(&thread->m_map, NULL))
		ft_perror_exit(E_MUTEX, info);
	else
		thread->mut_map = 1;
	if (pthread_mutex_init(&thread->m_user_x, NULL))
		ft_perror_exit(E_MUTEX, info);
	else
		thread->mut_x = 1;
	if (pthread_mutex_init(&thread->m_user_y, NULL))
		ft_perror_exit(E_MUTEX, info);
	else
		thread->mut_y = 1;
	if (pthread_mutex_init(&thread->m_user_d, NULL))
		ft_perror_exit(E_MUTEX, info);
	else
		thread->mut_d = 1;
	if (pthread_mutex_init(&thread->m_stop, NULL))
		ft_perror_exit(E_MUTEX, info);
	else
		thread->mut_stop = 1;
	return ;
}

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	t_thread	*ft_init_thread(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_thread initialise thread structure and init all mutex.
 * </description>
 *
 * <param type="t_info *" name="info">info structure</param>
 * <param type="t_thread *" name="thread">thread structure</param>
 *
 * <return>
 * 	t_thread structure.
 * </return>
 *
 */
t_thread	*ft_init_thread(t_info *info)
{
	t_thread	*thread;

	thread = (t_thread *) ft_calloc(1, sizeof(t_thread));
	if (!thread)
		ft_perror_exit(E_MALLOC, info);
	ft_init_mutex(info, thread);
	return (thread);
}


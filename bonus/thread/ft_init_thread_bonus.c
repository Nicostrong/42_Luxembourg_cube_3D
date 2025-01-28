/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:02:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/28 10:06:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"

/*
 * <cat>cube3D</cat>
 *
 * <summary>
 * 	void	ft_init_single_mutex(t_info *info, pthread_mutex_t *mut, int *flag)
 * </summary>
 *
 * <description>
 * 	ft_init_single_mutex initialise a single mutex and check if it fail and set 
 * 	the flag to 1 in success.
 * </description>
 *
 * <param type="t_info *" name="info">info structure</param>
 * <param type="pthread_mutex_t *" name="mut">mutex to init</param>
 * <param type="int *" name="flag">flag of mutex</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_init_single_mutex(t_info *info, pthread_mutex_t *mut, int *flag)
{
	if (pthread_mutex_init(mut, NULL))
		ft_perror_exit(E_MUTEX, info);
	*flag = 1;
	return ;
}

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
	ft_init_single_mutex(info, &thread->m_map, &thread->mut_map);
	ft_init_single_mutex(info, &thread->m_x, &thread->mut_x);
	ft_init_single_mutex(info, &thread->m_y, &thread->mut_y);
	ft_init_single_mutex(info, &thread->m_user_x, &thread->mut_user_x);
	ft_init_single_mutex(info, &thread->m_user_y, &thread->mut_user_y);
	ft_init_single_mutex(info, &thread->m_user_d, &thread->mut_user_d);
	ft_init_single_mutex(info, &thread->m_stop, &thread->mut_stop);
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


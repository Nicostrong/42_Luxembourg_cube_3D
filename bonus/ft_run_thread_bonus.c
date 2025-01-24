/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_thread_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:03:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 11:03:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

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
 * 	ft_create_thread create each thread for cub3D.
 * 	Execute each thread with the runtime and wait the end of each thread.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * 
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_create_thread(t_info *info, t_thread *thread)
{
	int	ret;

	ret = 0;
	ret = pthread_create(&thread->t_mini, NULL, &ft_run_mini, info);
	if (ret)
		ft_perror_exit(E_THREAD, info);
	ret = pthread_create(&thread->t_game, NULL, &ft_run_raycast, info);
	if (ret)
		ft_perror_exit(E_THREAD, info);
	ret = pthread_join(thread->t_mini, NULL);
	if (ret)
		ft_perror_exit(E_JOIN_TH, info);
	ret = pthread_join(thread->t_game, NULL);
	if (ret)
		ft_perror_exit(E_JOIN_TH, info);
}

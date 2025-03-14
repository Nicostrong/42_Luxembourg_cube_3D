/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:32:59 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_perror_exit(char *str_error, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_perror_exit print an error message on stderror and free the structure.
 * </description>
 *
 * <param type="char *" name="str_error">string error to print</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit with code 1.
 * </return>
 *
 */

int	ft_perror_exit(char *str_error, t_info *info)
{
	if (str_error)
		ft_putendl_fd(str_error, 2);
	if (info)
		ft_free_info(info);
	exit(EXIT_FAILURE);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_exit(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_exit exit proprely the programm. End the loop and free the structure 
 * 	correctelly before to exit the program.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	exit with code 0.
 * </return>
 *
 */
int	ft_exit(t_info *info)
{
	if (info)
	{
		LOOP_END(info->mlx);
		ft_free_info(info);
	}
	exit(EXIT_SUCCESS);
}

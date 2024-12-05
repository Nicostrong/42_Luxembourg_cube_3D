/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:57:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/05 09:04:33 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/struct3d.h"
#include "../../includes/color.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_info	*ft_init_info(char *path)
 * </summary>
 *
 * <description>
 * 	ft_init_info allow all memory for the structure and initialise somes 
 * 	variables, and call ft_init_info2 and ft_init_img, ft_init_img2 and 
 * 	ft_init_anim to initialise all variables of the structure.
 * </description>
 *
 * <param type="char *" name="path">path of the map</param>
 *
 * <return>
 * 	a pointer to the structure full initisalized.
 * </return>
 *
 */

t_info	*ft_init_info(char *path)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_perror_exit(E_MALLOC, NULL);
	info->map_path = ft_strdup(path);
	ft_init_info2(info);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit_bonus("Error:\n\tmlx init failed.", info);
	ft_init_img(&info);
	ft_init_img2(&info);
	ft_init_anim(&info);
	return (info);
}
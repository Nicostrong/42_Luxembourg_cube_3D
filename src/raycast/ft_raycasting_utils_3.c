/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:50:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/raycasting.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_ray_list(t_lst_ray *lst_ray);
 * </summary>
 *
 * <description>
 * 	ft_free_ray_list free all element of the list of raycasting structure.
 * </description>
 *
 * <param type="t_lst_ray *" name="lst_ray">linked list of ray struct</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_free_ray_list(t_lst_ray *lst_ray)
{
	t_lst_ray	*tmp;

	while (lst_ray)
	{
		tmp = lst_ray;
		lst_ray = lst_ray->next;
		ft_free((void **)&tmp);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	add_ray_to_list(t_lst_ray **list, t_raycast ray)
 * </summary>
 *
 * <description>
 * 	add_ray_to_list add the ray structure to the linked list of ray.
 * </description>
 *
 * <param type="t_lst_ray *" name="lst_ray">linked list of ray struct</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	add_ray_to_list(t_lst_ray **list, t_raycast ray)
{
	t_lst_ray	*new;
	t_lst_ray	*temp;

	new = ft_calloc(1, sizeof(t_lst_ray));
	if (!new)
		return ;
	new->ray = ray;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

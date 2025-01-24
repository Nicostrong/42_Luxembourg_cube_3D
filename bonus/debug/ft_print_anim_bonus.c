/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_anim_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:05:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 15:17:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

static void	ft_print_anim_img(t_anim *anim)
{
	int	i;

	i = -1;
	while (++i < anim->nb_img)
		printf("\tpointer of image[%d] : %p\n", i, anim->array_img[i]);
	return ;
}

void	ft_print_anim(t_info *info)
{
	t_anim	*anim;

	printf("***************\n");
	printf(BBLUE"ANIM STRUCTURE\n"RESET);
	printf("***************\n");
	if (!info->c_anim)
	{
		printf(REDC"\tcollectable animation is NULL\n"RESET);
		return ;
	}
	anim = info->c_anim;
	printf("\tspeed: %d\n", anim->speed);
	printf("\tchrono: %d\n", anim->chrono);
	printf("\tcurrent image: %d\n", anim->cur_img);
	printf("\tnumber of image: %d\n", anim->nb_img);
	printf("\tsize of image: %d\n", anim->len);
	ft_print_anim_img(info->c_anim);
	return ;
}

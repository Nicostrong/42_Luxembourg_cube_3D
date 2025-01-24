/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:39:02 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 13:02:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	void	ft_init_anim_img(t_info *info, t_anim *col)
 * </summary>
 *
 * <description>
 * 	ft_init_anim_image initialise all image of the collectable animation.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="t_anim *" name="col">anim structure for collectable</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_init_anim_img(t_info *info, t_anim *col)
{
	col->array_img[0] = mlx_xpm_file_to_image(info->mlx, \
		"./gfx/anim/c0.xpm", &col->len, &col->len);
	if (!col->array_img[0])
		ft_perror_exit("Error:\n\tc_0_img load fail.", info);
	col->array_img[1] = mlx_xpm_file_to_image(info->mlx, \
		"./gfx/anim/c1.xpm", &col->len, &col->len);
	if (!col->array_img[1])
		ft_perror_exit("Error:\n\tc_1_img load fail.", info);
	col->array_img[2] = mlx_xpm_file_to_image(info->mlx, \
		"./gfx/anim/c2.xpm", &col->len, &col->len);
	if (!col->array_img[2])
		ft_perror_exit("Error:\n\tc_2_img load fail.", info);
	col->array_img[3] = mlx_xpm_file_to_image(info->mlx, \
		"./gfx/anim/c3.xpm", &col->len, &col->len);
	if (!col->array_img[3])
		ft_perror_exit("Error:\n\tc_3_img load fail.", info);
	return ;
}

/*
 * <cat>so_long</cat>
 *
 * <summary>
 * 	t_anim	*ft_init_anim(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_anim initialise the animation structure for collectable.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	pointer to animation structure of collectable.
 * </return>
 *
 */

t_anim	*ft_init_anim(t_info *info)
{
	t_anim	*col;

	col = (t_anim *)ft_calloc(1, sizeof(t_anim));
	if (!col)
		ft_perror_exit(E_MALLOC, NULL);
	col->speed = SPEED_COL;
	col->chrono = 0;
	col->cur_img = CUR_COL;
	col->nb_img = N_COL;
	col->len = S_COL;
	printf("col->speed : %d\n", col->speed);
	printf("col->chrono : %d\n", col->chrono);
	printf("col->cur_img : %d\n", col->cur_img);
	printf("col->nb_img : %d\n", col->nb_img);
	printf("col->len : %d\n", col->len);
	col->array_img = (void **)ft_calloc(col->nb_img, sizeof(void *));
	if (!col->array_img)
		ft_perror_exit(E_MALLOC, NULL);
	ft_init_anim_img(info, col);
	return (col);
}
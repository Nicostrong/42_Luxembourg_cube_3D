/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_circle_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:28:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/03 09:49:20 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_pixel_put(t_info *info, int x, int y, int color)
 * </summary>
 *
 * <description>
 * 	ft_pixel_put set a pixel value at the coordinates x and y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 * <param type="int" name="color">value of pixel color</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->mini->addr + (y * info->mini->size + x * (info->mini->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	coloris_axe_2(t_info *info, int centx, int centy, int x, int y)
 * </summary>
 *
 * <description>
 * 	coloris_axe_2 is a function that draws a circle in the second and third 
 * 	octant.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="centx">center in x</param>
 * <param type="int" name="centy">center in y</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	coloris_axe_2(t_info *info, int x, int y)
{
	int	i;
	int	px;
	int	nx;
	int	py;
	int	ny;

	px = info->centx + y;
	nx = info->centx - y;
	py = info->centy + x;
	ny = info->centy - x;
	i = nx;
	while (i <= px)
	{
		if (py >= 0 && (py <= HEIGHT || py <= WIDTH))
			ft_pixel_put(info, i, py, ft_get_color(0, 0, 0, 255));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(info, i, ny, ft_get_color(0, 0, 0, 255));
		i++;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	coloris_axe_1(t_info *info, int centx, int centy, int x, int y)
 * </summary>
 *
 * <description>
 * 	coloris_axe_1 is a function that draws a circle in the first and fourth
 * 	octant.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="centx">center in x</param>
 * <param type="int" name="centy">center in y</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	coloris_axe_1(t_info *info, int x, int y)
{
	int	i;
	int	px;
	int	nx;
	int	py;
	int	ny;

	px = info->centx + x;
	nx = info->centx - x;
	py = info->centy + y;
	ny = info->centy - y;
	i = nx;
	while (i <= px)
	{
		if (py >= 0 && (py <= HEIGHT || py <= WIDTH))
			ft_pixel_put(info, i, py, ft_get_color(0, 0, 0, 255));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(info, i, ny, ft_get_color(0, 0, 0, 255));
		i++;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_put_circle(t_info *info, int centx, int centy)
 * </summary>
 *
 * <description>
 * 	ft_put_circle is a function that draws a circle in center x and y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="centx">center in x</param>
 * <param type="int" name="centy">center in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_put_circle(t_info *info, int centx, int centy)
{
	int	x;
	int	y;

	x = 0;
	y = PRAY;
	if (centx < 0 || centx >= WIDTH - PRAY || \
		centy < 0 - PRAY || centy >= HEIGHT - PRAY)
		return ;
	info->centx = centx;
	info->centy = centy;
	while (y >= x)
	{
		coloris_axe_1(info, x, y);
		coloris_axe_2(info, x, y);
		x++;
		if (x * x + y * y > PRAY * PRAY)
			y--;
	}
	return ;
}

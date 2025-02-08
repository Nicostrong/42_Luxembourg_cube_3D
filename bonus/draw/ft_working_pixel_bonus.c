/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_working_pixel_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:17:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 14:45:10 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	unsigned int	ft_get_pixel_color(t_img *img, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_get_pixel_color is a function that returns the color of a pixel in an 
 * 	image.
 * </description>
 *
 * <param type="t_img *" name="img">image to extract the pixel</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
unsigned int	ft_get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0);
	pixel = img->addr;
	pixel += (y * img->size) + (x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_put_pixel_color(t_win *win, int x, int y, int color)
 * </summary>
 *
 * <description>
 * 	ft_put_pixel_color is a function that draws a pixel in a window.
 * </description>
 *
 * <param type="t_win *" name="win">window destination</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 * <param type="int" name="color">pixel value</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_put_pixel_color(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->size + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_put_imgalpha(t_win *img_d, t_img *img_s, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_put_imgalpha is a function that draws an image with alpha channel.
 * </description>
 *
 * <param type="t_win *" name="imd_d">window destination</param>
 * <param type="t_img *" name="img_s">image with alpha to include</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_put_imgalpha(t_win *img_d, t_img *img_s, int x, int y)
{
	int				height;
	int				width;
	unsigned int	pixel_color;
	unsigned int	*dest_pixel;
	unsigned char	alpha;

	height = -1;
	while (++height < img_s->h)
	{
		width = -1;
		while (++width < img_s->w)
		{
			pixel_color = ft_get_pixel_color(img_s, width, height);
			alpha = (pixel_color >> 24) & 0xFF;
			if (!alpha)
			{
				dest_pixel = (unsigned int *) \
					(img_d->addr + (height + y) * img_d->size + \
					(width + x) * (img_d->bpp / 8));
				*dest_pixel = pixel_color;
			}
		}
	}
}

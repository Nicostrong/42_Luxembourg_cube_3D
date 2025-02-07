/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_working_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:17:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 11:03:09 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	unsigned int	ft_get_pixel_color(t_img *img, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_get_pixel_color read the value of the pixel in an image with the address 
 * 	x and y.
 * </description>
 *
 * <param type="t_img *" name="img">image structure to search the pixel</param>
 * <param type="int" name="x">coordonate in x</param>
 * <param type="int" name="y">coordonate in y</param>
 *
 * <return>
 * 	the valure of the pixel research.
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
 * 	ft_put_pixel_color write the value of the pixel color on the window image 
 *  with the address x and y.
 * </description>
 *
 * <param type="t_win *" name="win">window structure to set the pixel</param>
 * <param type="int" name="x">coordonate in x</param>
 * <param type="int" name="y">coordonate in y</param>
 * <param type="int" name="color">value of the pixel</param>
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
 * 	ft_put_imagalpha put an image with transparency on an image of window.
 * 	Put the image with transparency at the specific coordonate.
 * </description>
 *
 * <param type="t_win *" name="img_d">window structure of destination</param>
 * <param type="t_img *" name="img_s">image structure with transparency</param>
 * <param type="int" name="x">coordonate in x</param>
 * <param type="int" name="y">coordonate in y</param>
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
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:16:22 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:29:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

#define D_GREEN 65280

/*static void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}*/

void	put_pixel_image(t_pixel pixel, char *str, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int len;

	len = 64; /* En réalité, il s'agit de la longueur de votre image. Ici, mon image et ma fenêtre font la même taille */

	/* in this part you'll see how i decompose a decimal color in a third part decimal color rgb(255, 255, 255)*/
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	/* to understand try this */
	/* printf("r : %d | g : %d | b : %d\n", );*/

	/* (pixel.x * 4) + (len * 4 * pixel.y) : target of the first bit of the pixel */
	str[(pixel.x * 4) + (len * 4 * pixel.y)] = b;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 1] = g;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 2] = r;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 3] = 0;
}

/*void    print_square(t_data *f, int len_in_pixels)
{
	t_pixel		pix;
	int			y_stop;
	int			x_stop;

	x_stop = 0 + len_in_pixels;
	y_stop = 0 + len_in_pixels;
	pix.y = 0;

	while (pix.y != y_stop)
	{
		pix.x = 0;
		while (pix.x != x_stop)
		{
			put_pixel_image(pix, f->addr, D_GREEN);
			pix.x++;
		}
		pix.y++;
	}
}*/

void    ft_render(t_data *f)
{
    //ft_pixel_put(f, 5, 5, 0x00FF0000);
    //print_square(f, 500); /* print a square look for it to understand how to put pixel in image */

	int i;

    i = 0;
    while (i < NBTEXTURES)
	{
		if (f->gfx[i].addr)
		{
			mlx_put_image_to_window(f->mlx, f->win, f->gfx[i].addr, 0, 0);
			sleep (1);
		}
		i++;
	}
}
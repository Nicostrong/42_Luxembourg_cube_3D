/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/05 10:50:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

unsigned int	ft_get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0);
	pixel = img->addr;
	pixel += (y * img->size) + (x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

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

void	ft_put_player(t_info *info, t_img *player, int x, int y)
{
	if (player && player->addr)
	{
		ft_put_imgalpha(info->mini, info->player, x - (info->player->w / 2), \
			y - (info->player->h / 2));
		mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, \
			0, 0);
	}
	else
		ft_put_circle(info, x, y);
	return ;
}

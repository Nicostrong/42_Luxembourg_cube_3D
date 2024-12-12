/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/12 20:17:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/structures.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 *	cube_3D
 * </summary>
 *
 * <description>
 *	cube_3D is a 3D game playing with a map. The programm need to be lauching 
 *	with a path to the map. The map need to be *.cub.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	0 in success or 1 in error.
 * </return>
 *
 */
int main(int argc, char *argv[])
{
	t_info	*info;

	ft_check_arg(argc, argv);
	info = ft_get_all_info(argv[1]);
	ft_print_info(info);

	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel, size_line, endian;
	int		width = 500;
	int		height = 300;
	int		x, y, color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "MiniMap");
	img = mlx_new_image(mlx, width, height);
	data_addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian); 
	y = -1;
	while (++y < info->h)
	{
		x = -1;
		while (++x < info->w)
		{
			if (!info->map[y][x] || info->map[y][x] == '0' )
				color = 0x7F7F7F;
			else if (info->map[y][x] == '1')
				color = 0x000000;
			else if (info->map[y][x] == 'S')
				color = 0x0000FF;
			else
				color = 0x7F7F7F;
			for (int dy = 0; dy < 20; ++dy)
			{
				for (int dx = 0; dx < 20; ++dx)
				{
					int pixel_index = ((y * 20 + dy) * size_line) + ((x * 20 + dx) * (bits_per_pixel / 8));
					data_addr[pixel_index] = color & 0xFF;
					data_addr[pixel_index + 1] = (color >> 8) & 0xFF;
					data_addr[pixel_index + 2] = (color >> 16) & 0xFF;
				}
			}
		}
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);

	/*ft_init_mlx(info);
	mlx_hook(info->win, 17, 0, &ft_exit, info);
	mlx_loop(info->mlx);
	mlx_mouse_hook(f.win, &mouse_click, &f);
	mlx_hook(f.win, 2, 1L << 0, &pr_key, &f);
	mlx_hook(f.win, 3, 1L << 1, &rl_key, &f);
	mlx_hook(f.win, 6, 1L << 6, &mouse_move, &f);
	mlx_loop_hook(f.mlx, update_key, &f);
	mlx_loop(f.mlx);*/
	return (0);
}
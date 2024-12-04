/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 13:46:14 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "./src/src.h"

int main(int argc, char *argv[])
{
	t_data	f;

	init_struct(&f);
	if (argc != 2)
	{
		printf("\033[1;31mUsage\n - ./cub3d <map.cub>\033[0m\n");
		ft_errclose(&f);
	}
	fic_init(&f, argv[1]);
	if (is_ficexiste(f.fic))
		ft_vali(f.fic, &f);
	else
	{
		ft_printf_error("\033[1;31mError\n - Missing file.\033[0m\n");
		ft_errclose(&f);
	}
	ft_init_mlx(&f);
	mlx_hook(f.win, 17, 0, &ft_close, &f);
	mlx_mouse_hook(f.win, &mouse_click, &f);
	mlx_hook(f.win, 2, 1L << 0, &pr_key, &f);
	mlx_hook(f.win, 3, 1L << 1, &rl_key, &f);
	mlx_hook(f.win, 6, 1L << 6, &mouse_move, &f);
	mlx_loop_hook(f.mlx, update_key, &f);
	mlx_loop(f.mlx);
	return (0);
}

	/*printf("##############################################\n");
	printf("			MISSING FILE\n");
	printf("##############################################\n\n");
	printf("##############################################\n");
	printf("fic = vmap_simpl.cub\n");
	fic_init(&f, "vmap_simpl.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/



	/*printf("##############################################\n");
	printf("			GOOD MAP\n");
	printf("##############################################\n\n");
	printf("##############################################\n");
	printf("fic = vmap_simple0.cub\n");
	fic_init(&f, "vmap_simple0.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = vmap_cub0.cub\n");
	fic_init(&f, "vmap_cub0.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;	
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = vmap_cub1.cub\n");
	fic_init(&f, "vmap_cub1.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = vmap_zarb0.cub\n");
	fic_init(&f, "vmap_zarb0.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/



	/*printf("##############################################\n");
	printf("			BAD MAP\n");
	printf("##############################################\n\n");
	printf("##############################################\n");
	printf("fic = bmap_zarb0_f.cub\n");
	fic_init(&f, "bmap_zarb0_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb1_f.cub\n");
	fic_init(&f, "bmap_zarb1_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb2_f.cub\n");
	fic_init(&f, "bmap_zarb2_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb3_f.cub\n");
	fic_init(&f, "bmap_zarb3_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb4_f.cub\n");
	fic_init(&f, "bmap_zarb4_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb5_f.cub\n");
	fic_init(&f, "bmap_zarb5_f.cub"); //passe malgrer le false
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb6_f.cub\n");
	fic_init(&f, "bmap_zarb6_f.cub");
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb7_f.cub\n");
	fic_init(&f, "bmap_zarb7_f.cub"); //passe malgrer le false
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/

	/*printf("##############################################\n");
	printf("fic = bmap_zarb8_f.cub\n");
	fic_init(&f, "bmap_zarb8_f.cub");//passe malgrer le false
	ft_vali(f.fic, &f);
	f.fic = NULL;
	printf("##############################################\n\n");*/
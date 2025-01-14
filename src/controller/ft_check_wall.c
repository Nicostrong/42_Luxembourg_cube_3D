/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:57:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/14 20:20:48 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_isforbidden_zone(t_info *info, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_isforbidden_zone check if the player go to a forbidden zone.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	1 if in forbidden zone or 0 if not.
 * </return>
 *
 */
/*
static int	ft_isforbidden_zone(t_info *info, double new_x, double new_y)
{
	int	dirx;
	int	diry;

	dirx = (new_x > info->user_x) - (new_x < info->user_x);
	diry = (new_y > info->user_y) - (new_y < info->user_y);
	if (dirx > 0 && diry > 0)
	{
		printf("corner right/down\n");
		return (info->map[info->y + 1][info->x] == '0' && \
			info->map[info->y][info->x + 1] == '0' && \
			info->map[info->y + 1][info->x + 1] == '1');
	}
	if (dirx > 0 && diry < 0)
	{
		printf("corner right/up\n");
		return (info->map[info->y - 1][info->x] == '0' && \
			info->map[info->y][info->x + 1] == '0' && \
			info->map[info->y - 1][info->x + 1] == '1');
	}
	if (dirx < 0 && diry > 0)
	{
		printf("corner left/down\n");
		return (info->map[info->y + 1][info->x] == '0' && \
			info->map[info->y][info->x - 1] == '0' && \
			info->map[info->y + 1][info->x - 1] == '1');
	}
	if (dirx < 0 && diry < 0)
	{
		printf("corner left/up\n");
		return (info->map[info->y - 1][info->x] == '0' && \
			info->map[info->y][info->x - 1] == '0' && \
			info->map[info->y - 1][info->x - 1] == '1');
	}
	if (dirx > 0)
	{
		printf("right\n");
		return (info->map[info->y][info->x + 1] == '1');
	}
	if (dirx < 0)
	{
		printf("left\n");
		return (info->map[info->y][info->x - 1] == '1');
	}
	if (diry > 0)
	{
		printf("down\n");
		return (info->map[info->y + 1][info->x] == '1');
	}
	if (dirx < 0)
	{
		printf("up\n");
		return (info->map[info->y - 1][info->x] == '1');
	}
	return (0);
}*/

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_x check if the player go to a wall or a forbidden zone in axis x.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="dirx">direction of the player in x</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
/*static void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
{
	int		x;
	int		y;
	double	deci_x;
	double	deci_y;

	(void)dirx;
	deci_x = *new_x - info->x;
	deci_y = *new_y - info->y;
	x = info->x;
	y = info->y;
	printf("\tAXE X\n");
	if (deci_x < D_WALL)
	{
		printf("\t\tnew_x < D_WALL => deci_x = %.2f\tdeci_y = %.2f\n", deci_x, deci_y);
		printf("%s", info->map[y - 1][x - 1] == '1' ? "MUR HAUT GAUCHE\n" : "");
		printf("%s", info->map[y][x - 1] == '1' ? "MUR GAUCHE\n" : "");
		printf("%s", info->map[y + 1][x - 1] == '1' ? "MUR BAS GAUCHE\n" : "");
		if (info->map[y][x - 1] == '1')
		{
			printf("\t\tcolision direct a gauche => on bride X\n");
			*new_x = x + D_WALL;
		}
		else if ((info->map[y - 1][x - 1] == '1'  && deci_y < D_WALL) || (info->map[y + 1][x - 1] == '1' && deci_y > 1 - D_WALL))
		{
			printf("\t\tcolision GAUCHE CORNER detecte => new_x BRIDE @ D_WALL\n");
			*new_x = x + D_WALL;
		}
	}
	else if (deci_x > (1 - D_WALL))
	{
		printf("\t\tnew_x > 1 - D_WALL => deci_x = %.2f\tdeci_y = %.2f\n", deci_x, deci_y);
		printf("%s", info->map[y - 1][x + 1] == '1' ? "MUR HAUT DROITE\n" : "");
		printf("%s", info->map[y][x + 1] == '1' ? "MUR DROITE\n" : "");
		printf("%s", info->map[y + 1][x + 1] == '1' ? "MUR BAS DROITE\n" : "");
		if (info->map[y][x + 1] == '1')
		{
			printf("\t\tcolision directe a DROITE detecte => new_x BRIDE @ D_WALL\n");
			*new_x = x + 1 - D_WALL;
		}
		else if ((info->map[y - 1][x + 1] == '1' && deci_y < D_WALL) || (info->map[y + 1][x + 1] == '1' && deci_y > 1 - D_WALL))
		{
			printf("\t\tcolision DROITE CORNER detecte => new_x BRIDE @ D_WALL\n");
			*new_x = x + 1 - D_WALL;
		}
	}
}*/
/*
static void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
{
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	printf("\t\t\tAXE X\n");
	if (info->map[y][x + dirx] == '1')
	{
		printf("\t\t\tDIRECT WALL X we limits.\n");
		if (dirx < 0 && *new_x - x < D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
	}
	if (ft_isforbidden_zone(info, *new_x, *new_y))
	{
		printf("\t\t\tFORBIDDEN ZONE X we limit.\n");
		if (dirx < 0 && *new_x - x < D_WALL && \
			(*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL && \
			(*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + 1 - D_WALL;
	}
}*/

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_y(t_info *info, int diry, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_y check if the player go to a wall or a forbidden zone in axis y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="diry">direction of the player in y</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
/*static void	ft_check_y(t_info *info, int diry, double *new_y, double *new_x)
{
	int		x;
	int		y;
	double	deci_x;
	double	deci_y;

	(void)diry;
	deci_x = *new_x - info->x;
	deci_y = *new_y - info->y;
	x = info->x;
	y = info->y;
	printf("\tAXE Y\n");
	if (deci_y < D_WALL)
	{
		printf("\t\tnew_y < D_WALL => deci_x = %.2f\tdeci_y = %.2f\n", deci_x, deci_y);
		printf("%s", info->map[y - 1][x - 1] == '1' ? "MUR HAUT GAUCHE\n" : "");
		printf("%s", info->map[y - 1][x] == '1' ? "MUR HAUT\n" : "");
		printf("%s", info->map[y - 1][x + 1] == '1' ? "MUR HAUT DROIT\n" : "");
		if (info->map[y - 1][x] == '1')
		{
			printf("\t\tcolision detecte HAUT => new_y BRIDE @ D_WALL\n");
			*new_y = y + D_WALL;
		}
		else if ((info->map[y - 1][x - 1] == '1' && deci_x < D_WALL) || (info->map[y - 1][x + 1] == '1' && deci_x > 1 - D_WALL))
		{
			printf("\t\tcolision detecte HAUT CORNER => new_y BRIDE @ D_WALL\n");
			*new_y = y + D_WALL;
		}
		
	}
	else if (deci_y > (1 - D_WALL))
	{
		printf("\t\tnew_y > 1 - D_WALL => deci_x = %.2f\tdeci_y = %.2f\n", deci_x, deci_y);
		printf("%s", info->map[y + 1][x - 1] == '1' ? "MUR BAS GAUCHE\n" : "");
		printf("%s", info->map[y + 1][x] == '1' ? "MUR BAS\n" : "");
		printf("%s", info->map[y + 1][x + 1] == '1' ? "MUR BAS DROITE\n" : "");
		if (info->map[y + 1][x] == '1')
		{
			printf("\t\tcolision detecte BAS => new_y BRIDE @ D_WALL\n");
			*new_y = y + 1 - D_WALL;
		}
		else if ((info->map[y + 1][x - 1] == '1' && deci_x < D_WALL) || (info->map[y + 1][x + 1] == '1' && deci_x > 1 - D_WALL))
		{
			printf("\t\tcolision detecte BAS CORNER => new_y BRIDE @ D_WALL\n");
			*new_y = y + 1 - D_WALL;
		}
	}
}*/

/*
static void	ft_check_y(t_info *info, int diry, double *new_y, double *new_x)
{
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	printf("\t\t\tAXE Y\n");
	if (info->map[y + diry][x] == '1')
	{
		printf("\t\t\tWALL DIRECT in Y we limit.\n");
		if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
			*new_y = floor(*new_y) + D_WALL;
		else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
			*new_y = ceil(*new_y) - D_WALL;
	}
	if (ft_isforbidden_zone(info, *new_x, *new_y))
	{
		printf("\t\t\tFORBIDDEN ZONE Y we limit.\n");
		if (diry < 0 && *new_y - y < D_WALL && \
			(*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
			*new_y = y + D_WALL;
		else if (diry > 0 && *new_y - y > 1 - D_WALL && \
			(*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
			*new_y = y + 1 - D_WALL;
	}
}*/

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_limit_pos(t_info *info, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_adjust_pads limite the value of pad near a wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new padx of the player</param>
 * <param type="double" name="new_pady">new pady of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_check_wall(t_info *info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);	//	-1 GAUCHE / 0 / 1 DROITE
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);	//	-1 HAUT / 0 / 1 BAS
	printf("******************************\n");
	printf("\tCHECK WALLL\n");
	printf("******************************\n");
	printf("\tdirx: %d\tdiry: %d\n", dirx, diry);
	printf("\tdirx: %s", dirx == -1 ? "GAUCHE" : dirx == 1 ? "DROITE" : "BOUGE PAS EN X");
	printf("\tdiry: %s\n", diry == -1 ? "MONTER" : diry == 1 ? "DESCENDRE" : "BOUGE PAS EN Y");
	printf("\tnew_x: %.2f\tnew_y: %.2f\n", *new_x, *new_y);
	//	si deplacement en diagonal
	if (dirx && diry)
	{
		printf("deplacement en diagonal");
		//	si mur a gauche ou droite
		if (info->map[info->y][info->x + dirx] == '1')
		{
			printf("\tmur en X");
			//	si deplacement vers la gauche et zone rouge
			if (dirx == -1 && (*new_x - info->x) < D_WALL)
			{
				printf("\tGAUCHE et ROUGE");
				*new_x = info->x + D_WALL;
			}
			//	si deplacement vers la droite et zone rouge
			else if (dirx == 1 && (*new_x - info->x) > 1 - D_WALL)
			{
				printf("\tDROIT et ROUGE");
				*new_x = info->x + 1 - D_WALL;
			}
		}
		//	si mur en haut ou en bas
		if (info->map[info->y + diry][info->x] == '1')
		{
			printf("\tmur en Y");
			//	si deplacement vers le haut et zone rouge
			if (diry == -1 && (*new_y - info->y) < D_WALL)
			{
				printf("\tHAUT et ROUGE");
				*new_y = info->y + D_WALL;
			}
			//	si deplacement vers le bas et zone rouge
			else if (diry == 1 && (*new_y - info->y) > 1 - D_WALL)
			{
				printf("\tBAS et ROUGE");
				*new_y = info->y + 1 - D_WALL;
			}
		}
		//	si mur en diagonal
		else if (info->map[info->y + diry][info->x + dirx] == '1')
		{
			printf("\tmur en diag");
			//	si deplacement vers la gauche et en zone rouge en x et en y haut
			if (dirx == -1 && ((*new_x - info->x) < D_WALL && ((*new_y - info->y) < D_WALL) && diry == -1))
			{
				printf("\tGAUCHE et HAUT et ROUGE");
				*new_x = info->x + D_WALL;
			}
			// si deplacement vers la gauche et en zone rouge en x et en y bas
			else if (dirx == -1 && ((*new_x - info->x) < D_WALL && ((*new_y - info->y) > 1 - D_WALL) && diry == 1))
			{
				printf("\tGAUCHE et BAS et ROUGE");
				*new_x = info->x + D_WALL;
			}
			//	si deplacement vers la droite et en zone rouge en x et en y haut
			else if (dirx == 1 && ((*new_x - info->x) > 1 - D_WALL && ((*new_y - info->y) < D_WALL) && diry == -1))
			{
				printf("\tDROITE et HAUT et ROUGE");
				*new_x = info->x + 1 - D_WALL;
			}
			//	si deplacement vers la droite et en zone rouge en x et en y bas
			else if (dirx == 1 && ((*new_x - info->x) > 1 - D_WALL && ((*new_y - info->y) > 1 - D_WALL) && diry == 1))
			{
				printf("\tDROITE et BAS et ROUGE");
				*new_x = info->x + 1 - D_WALL;
			}
			//	si deplacement vers le haut et en zone rouge en y et en x gauche
			else if (diry == -1 && ((*new_y - info->y) < D_WALL && ((*new_x - info->x) < D_WALL) && dirx == -1))
			{
				printf("\tHAUT et GAUCHE et ROUGE");
				*new_y = info->y + D_WALL;
			}
			//	si deplacement vers le haut et en zone rouge en y et en x droite
			else if (diry == -1 && ((*new_y - info->y) < D_WALL && ((*new_x - info->x) > 1 - D_WALL) && dirx == 1))
			{
				printf("\tHAUT et DROITE et ROUGE");
				*new_y = info->y + D_WALL;
			}
			//	si deplacement vers le bas et en zone rouge en y et en x gauche
			else if (diry == 1 && ((*new_y - info->y) > 1 - D_WALL && ((*new_x - info->x) < D_WALL) && dirx == -1))
			{
				printf("\tBAS et GAUCHE et ROUGE");
				*new_y = info->y + 1 - D_WALL;
			}
			//	si deplacement vers le bas et en zone rouge en y et en x droite
			else if (diry == 1 && ((*new_y - info->y) > 1 - D_WALL && ((*new_x - info->x) > 1 - D_WALL) && dirx == 1))
			{
				printf("\tBAS et DROITE et ROUGE");
				*new_y = info->y + 1 - D_WALL;
			}
		}
	}
	else if (dirx)
	{
		printf("deplacement en X");
		//	si mur a gauche ou droite
		if (info->map[info->y][info->x + dirx] == '1')
		{
			printf("\tGAUCHE ou DROITE");
			//	si deplacement vers la gauche et zone rouge
			if (dirx == -1 && (*new_x - info->x) < D_WALL)
			{
				printf("\tGAUCHE et ROUGE");
				*new_x = info->x + D_WALL;
			}
			//	si deplacement vers la droite et zone rouge
			else if (dirx == 1 && (*new_x - info->x) > 1 - D_WALL)
			{
				printf("\tDROITE et ROUGE");
				*new_x = info->x + 1 - D_WALL;
			}
		}
	}
	else if (diry)
	{
		printf("deplacement en Y");
		//	si mur en haut ou en bas
		if (info->map[info->y + diry][info->x] == '1')
		{
			printf("\tHAUT ou BAS");
			//	si deplacement vers le haut et zone rouge
			if (diry == -1 && (*new_y - info->y) < D_WALL)
			{
				printf("\tHAUT et ROUGE");
				*new_y = info->y + D_WALL;
			}
			//	si deplacement vers le bas et zone rouge
			else if (diry == 1 && (*new_y - info->y) > 1 - D_WALL)
			{
				printf("\tBAS et ROUGE");
				*new_y = info->y + 1 - D_WALL;
			}
		}
	}
	printf("\n");
	printf("\tnew_x: %.2f\tnew_y: %.2f\n", *new_x, *new_y);
}

/*
void	ft_check_wall(t_info *info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	printf("******************************\n");
	printf("\tCHECK WALLL\n");
	printf("******************************\n");
	printf("\tdirx: %d\tdiry: %d\n", dirx, diry);
	printf("\tnew_x: %.2f\tnew_y: %.2f\n", *new_x, *new_y);
	if (diry && dirx)
	{
		ft_check_x(info, dirx, new_x, new_y);
		ft_check_y(info, diry, new_y, new_x);
	}
	else if (dirx != 0 && !diry)
		ft_check_x(info, dirx, new_x, new_y);
	else if (diry != 0 && !dirx)
		ft_check_y(info, diry, new_y, new_x);
	//ft_isforbidden_zone(info, new_x, new_y);
	printf("\tnew_x: %.2f\tnew_y: %.2f\n", *new_x, *new_y);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/05 12:09:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_set_dir_and_plan set the direction and the plan of the raycasting.
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
{
	ray->dir_x = cos(info->user_deg);
	ray->dir_y = sin(info->user_deg);
	ray->plane_x = -ray->dir_y * T_HALF_FOV;
	ray->plane_y = ray->dir_x * T_HALF_FOV;
	ray->prev_draw_end = HEIGHT / 2;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_cal_ray_dir(t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_cal_ray_dir calculate the direction of the ray.
 * </description>
 *
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_cal_ray_dir(t_raycast *ray)
{
	double	camera_x;
	
	camera_x = 2 * ray->x / (double)(WIDTH - 1) - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * camera_x;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_dda(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_init_dda initialize the DDA algorithm.
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_init_dda(t_info *info, t_raycast *ray)
{
	ray->map_x = (int)info->user_x;
	ray->map_y = (int)info->user_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (info->user_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - info->user_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (info->user_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - info->user_y) * ray->delta_dist_y;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_hit_wall(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_hit_wall check if the ray hit a wall.
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_hit_wall(t_info *info, t_raycast *ray)
{
	while (info->map[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			ray->wall = 2;
			if (ray->step_x == -1)
				ray->wall = 0;
			ray->texture = info->w_e_img;
			if (ray->step_x == -1)
				ray->texture = info->w_w_img;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			ray->wall = 3;
			if (ray->step_y == -1)
				ray->wall = 1;
			ray->texture = info->w_s_img;
			if (ray->step_y == -1)
				ray->texture = info->w_n_img;
		}
	}
	return ;
}

void	add_ray_to_list(t_lst_ray **list, t_raycast ray)
{
	t_lst_ray	*new;
	t_lst_ray	*temp;

	new = ft_calloc(1, sizeof(t_lst_ray));
	if (!new)
		return ;
	new->ray = ray;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

void	ft_draw_column(t_info *info, int x, int draw_start, int draw_end, t_img *texture, int text_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	// Calcul du pas de texture : combien de pixels de texture on saute par pixel de l'écran
	step = 1.0 * texture->h / (draw_end - draw_start);
	tex_pos = 0;
	y = draw_start;
	while (y < draw_end)
	{
		// Calcul de la coordonnée Y sur la texture
		tex_y = (int)tex_pos & (texture->h - 1);
		tex_pos += step;
		// Récupération de la couleur du pixel dans la texture
		int	color = ft_get_pixel_color(texture, text_x, tex_y);
		// Dessiner le pixel sur l’image finale
		mlx_pixel_put(info->mlx, info->game->win, x, y, color);
		y++;
	}
}

void	ft_interpolate_rays(t_info *info, t_lst_ray *list)
{
	t_lst_ray	*current;
	t_lst_ray	*next;
	int			x;

	current = list;
	while (current && current->next)
	{
		next = current->next;
		x = current->ray.x;
		while (x < next->ray.x)
		{
			double t = (double)(x - current->ray.x) / (next->ray.x - current->ray.x);
			int draw_start = (1 - t) * current->ray.draw_start + t * next->ray.draw_start;
			int draw_end = (1 - t) * current->ray.draw_end + t * next->ray.draw_end;
			int text_x = (1 - t) * current->ray.text_x + t * next->ray.text_x;
			ft_draw_column(info, x, draw_start, draw_end, current->ray.texture, text_x);
			x++;
		}
		current = next;
	}
}

void	free_ray_list(t_lst_ray *lst_ray)
{
	t_lst_ray	*tmp;

	while (lst_ray)
	{
		tmp = lst_ray;
		lst_ray = lst_ray->next;
		ft_free((void **)&tmp);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_raycasting(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_raycasting display the map on the screan with a 3D view.
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
int	ft_raycasting(t_info *info)
{
	t_raycast	ray;
	t_raycast	prev_ray;
	t_lst_ray	*ray_list = NULL;

	mlx_clear_window(info->mlx, info->game->win);
	ft_set_dir_and_plan(info, &ray);
	ray.x = -1;
	while (++ray.x < WIDTH)
	{
		ft_cal_ray_dir(&ray);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		// Conditions pour enregistrer un rayon
		if (ray.x == 0 || ray.x == WIDTH - 1 || 
			ray.map_x != ray.prev_map_x || ray.map_y != ray.prev_map_y || 
			ray.x % 50 == 0 || 
			(ray.draw_start > 0 && prev_ray.draw_start == 0) || 
			(ray.draw_end < HEIGHT - 1 && prev_ray.draw_end == HEIGHT - 1) || 
			fabs(ray.perp_wall_dist - prev_ray.perp_wall_dist) > 0.1)
		{
			add_ray_to_list(&ray_list, ray);
			prev_ray = ray;
		}
		// Mettre à jour les positions précédentes
		ray.prev_map_x = ray.map_x;
		ray.prev_map_y = ray.map_y;
	}
	// Interpolation pour compléter les colonnes manquantes
	ft_interpolate_rays(info, ray_list);
	// Nettoyage de la mémoire
	//ft_free_ray_list(ray_list);
	while (ray_list)
	{
		ft_print_ray(info, &ray_list->ray);
		ray_list = ray_list->next;
	}
	// Rafraîchissement de l'affichage
	//mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
	info->move = 0;
	ft_minimap(info);
	return (0);
}

/*int	ft_raycasting(t_info *info)
{
	t_raycast	ray;
	double		z_buffer[WIDTH];

	if (!info->move)
		return (0);
	ft_set_dir_and_plan(info, &ray);
	ray.x = -1;
	while (++ray.x < WIDTH)
	{
		ft_cal_ray_dir(&ray);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		ray.color = W_WALL;		//	OUEST
		if (ray.wall == 1)
			ray.color = N_WALL;	//	NORD
		else if (ray.wall == 2)
			ray.color = S_WALL;	//	SUD
		else if (ray.wall == 3)
			ray.color = E_WALL;	//	EST
		else if (ray.wall == 4)
			ray.color = PINK;	//	DOOR
		ft_set_pixel(info, &ray);
		ray.prev_draw_end = ray.draw_end;
		z_buffer[ray.x] = ray.perp_wall_dist;
		ft_print_ray(info, &ray);
	}
	//ft_set_door_item(info, &ray, z_buffer);
	mlx_clear_window(info->mlx, info->game->win);
	mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
	info->move = 0;
	ft_minimap(info);
	return (0);
}*/

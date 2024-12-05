/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/05 07:32:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_GAME_H
# define SETTING_GAME_H

# define TITLE			"Cube3D"	//	Project name
# define WIDTH			800			//	1920
# define HEIGHT			600			//	1080
# define NBTEXTURES		6			//	Number of textures

# define ISAZERTY		0			//	bool keyboard azerty

/*
 *	Setting Mini Map
 */

# define PRAY 			5			//	size player on minimap
# define LENRAY			500			//	lenght ray
# define NBRAY			10			//	number ray
# define RAYECART		10.0		//	scale ray
# define WSCALE			4			//	size wall

/*
 *	Mouse setting
 */

# define LEFT_CLIC		1
# define MIDDLE_CLIC	2
# define RIGHT_CLIC		3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

/*
 *	FPS
 */

# define FPS 			30
# define FRAMT 			(1000 / FPS)
# define SPEED_COL		50000

/*
 *	Mouse sens
 */

# define SENSMOU 		1

#endif
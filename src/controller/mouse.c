/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:42:51 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:28:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

static void	move_lr(int x, int y, t_data *f)
{
	(void)y;

	if (f->userd.cooxm < x)
		f->userd.dir = (f->userd.dir + 1 + 360) % 360;
	else
		f->userd.dir = (f->userd.dir - 1 + 360) % 360;
	f->userd.cooxm = x;
}

//int	mouse_click(int mocde, int x, int y, t_data *f)
int	mouse_click(int mocde)
{
	if (mocde == LEFT_CLIC)
		printf("left clic\n");
	else if (mocde == RIGHT_CLIC)
		printf("right clic\n");
	else if (mocde == MIDDLE_CLIC)
		printf("middle clic\n");
	else if (mocde == SCROLL_UP)
		printf("scroll up\n");
	else if (mocde == SCROLL_DOWN)
		printf("scroll down\n");
	return (0);
}

int	mouse_move(int x, int y, t_data *f)
{	
	if (!(f->userd.cooxm == x))
		move_lr(x, y, f);
	//printf("Mouse = x / %d - y :/ %d\n", x, y);
	return (0);
}
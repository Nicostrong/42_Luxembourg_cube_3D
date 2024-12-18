
void	ft_print_box(t_info *info, int x, int y, int color)
{
	int	ox;
	int	oy;
	int	dx;
	int	dy;
	int	px;
	int	py;
	int	pixel_index;
	int	size;
	int	bpp;

	ox = (info->pad_x * 2) + 21;
	oy = (info->pad_y * 2) + 21;
	size = info->win_m->size_line;
	bpp = info->win_m->bpp / 8;
	dy = -1;
	while (++dy < 42)
	{
		py = (y * 42) + dy; // + oy;
		if (py < 0 || py >= MINI_H)
			continue ;
		dx = -1;
		while (++dx < 42)
		{
			px = (x * 42) + dx; // + ox;
			if (px < 0 || px >= MINI_W)
				continue ;
			pixel_index = (py * size) + (px  * bpp);
			info->win_m->addr[pixel_index] = color & 0xFF;
			info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
			info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;
		}
	}
}

static void	ft_draw_line(t_info *info, int *color, int y)
{
	int	index;
	int	i_color;
	int	ofset_x;
	int	x;

	i_color = -1;
	x = -1;
	while (++x < MINI_W)
	{
		index = (y * info->win_m->size_line) + (x * (info->win_m->bpp / 8));
		ofset_x = info->pad_x;
		while (ofset_x++ < 0)
		{
			info->win_m->addr[++index] = color[++i_color] & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 8) & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 16) & 0xFF;
			info->win_m->addr[++index] = 0xFF;
		}
		while (++i_color < 4)
		{
			info->win_m->addr[++index] = color[i_color] & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 8) & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 16) & 0xFF;
			info->win_m->addr[++index] = 0xFF;
		}
		ofset_x = info->pad_x;
		while (ofset_x++ < 0)
		{
			info->win_m->addr[++index] = color[++i_color] & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 8) & 0xFF;
			info->win_m->addr[++index] = (color[i_color] >> 16) & 0xFF;
			info->win_m->addr[++index] = 0xFF;
		}

	}
}

void	ft_render(t_info *info)
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	int	color[8];
	int	index;
	int	height;
	int	y;

	if (info->pad_y < 0)
	{
		y_start = info->user_y - 4;
		y_end = info->user_y + 2;
	}
	else if (info->pad_y == 0)
	{
		y_start = info->user_y - 3;
		y_end = info->user_y + 2;
	}
	else
	{
		y_start = info->user_y - 3;
		y_end = info->user_y + 3;
	}
	y = 0;
	while (++y_start <= y_end)
	{
		if (info->pad_x < 0)
		{
			x_start = info->user_x - 5;
			x_end = info->user_x + 3;
		}
		else if (info->pad_x == 0)
		{
			x_start = info->user_x - 4;
			x_end = info->user_x + 3;
		}
		else
		{
			x_start = info->user_x - 4;
			x_end = info->user_x + 4;
		}
		index = -1;
		while (++x_start < x_end)
		{
			if (x_start < 0 || y_start < 0 || x_start >= MINI_W || y_start >= MINI_H)
				color[++index] = 0xFF0000;	//	Red
			else if (info->map[y_start][x_start] \
				&& (info->map[y_start][x_start] == '0' \
				|| info->map[y_start][x_start] == 'P'))
				color[++index] = 0x7F7F7F;	//	Gray
			else if (info->map[y_start][x_start] \
				&& (info->map[y_start][x_start] == '1'))
				color[++index] = 0x0000FF;	//	Blue
			else
				color[++index] = 0xFFFF00;	//	Yellow
		}
		color[++index] = -1;
		height = -1;
		printf("y = %d\n", y);
		int	pad_y = info->pad_y;
		if (pad_y < 0)
			while (pad_y++ < 0)
				ft_draw_line(info, color, y++);
		else if (info->pad_y == 0)
			while (++height < 42)
				ft_draw_line(info, color, y++);
		else
			while (pad_y++ < 0)
			ft_draw_line(info, color, y++);
	}
	mlx_put_image_to_window(info->mlx, info->win_m->win, info->win_m->img, 0, 0);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->win_m->win, info->player->img, (MINI_W / 2) - 21, (MINI_H / 2) - 21);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
}

/*
	int pixel_index = (((yy * 42) + dy + oy) * info->win_m->size_line) \
		+ (((xx * 42) + dx - ox) * (info->win_m->bpp / 8));
	info->win_m->addr[pixel_index] = color & 0xFF;
	info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
	info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;
*/
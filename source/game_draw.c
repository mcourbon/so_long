/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:08:06 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/10 14:14:54 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_img(t_so_long *so_long, void *img, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win, img, x * 32, y * 32);
}

static void	draw_player(t_so_long *so_long, void *img, int x, int y)
{
	so_long->player_x = x;
	so_long->player_y = y;
	draw_img(so_long, img, x, y);
}

static void	draw_exit(t_so_long *so_long, int x, int y)
{
	if (so_long->nb_collect == 0)
		so_long->img_exit = so_long->img_exit_open;
	draw_img(so_long, so_long->img_exit, x, y);
}

static void	draw_collect(t_so_long *so_long, int x, int y)
{
	if ((so_long->moves % 2) == 0)
		so_long->img_collect = so_long->img_collect_left;
	else
		so_long->img_collect = so_long->img_collect_right;
	draw_img(so_long, so_long->img_collect, x, y);
}

int	draw_map(t_so_long *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (so_long->map[y][x] == '0')
				draw_img(so_long, so_long->img_grass, x, y);
			else if (so_long->map[y][x] == '1')
				draw_img(so_long, so_long->img_wall, x, y);
			else if (so_long->map[y][x] == 'C')
				draw_collect(so_long, x, y);
			else if (so_long->map[y][x] == 'E')
				draw_exit(so_long, x, y);
			else if (so_long->map[y][x] == 'P')
				draw_player(so_long, so_long->img_player, x, y);
		}
	}
	return (0);
}

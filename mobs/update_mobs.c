/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:03:09 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/12 11:25:33 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_mob_img(char key, t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->nb_mobs)
	{
		if (key == 'w')
			so_long->mobs[i].img_mob = so_long->img_mob_back;
		else if (key == 'd')
			so_long->mobs[i].img_mob = so_long->img_mob_right;
		else if (key == 's')
			so_long->mobs[i].img_mob = so_long->img_mob_front;
		else if (key == 'a')
			so_long->mobs[i].img_mob = so_long->img_mob_left;
		i++;
	}
}

void	update_mob_w(t_so_long *so_long, int i)
{
	update_mob_img('w', so_long);
	if ((so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == '1')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'C')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'E')
		|| (so_long->map[so_long->mobs[i].mob_y] \
		[so_long->mobs[i].mob_x] == 'M'))
		so_long->mobs[i].mob_y = so_long->mobs[i].mob_y + 1;
	else if (so_long->map[so_long->mobs[i].mob_y] \
		[so_long->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else
	{
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] = 'M';
		so_long->map[so_long->mobs[i].mob_y + 1][so_long->mobs[i].mob_x] = '0';
	}
	draw_map(so_long);
	draw_map_mobs(so_long);
}

void	update_mob_d(t_so_long *so_long, int i)
{
	update_mob_img('d', so_long);
	if ((so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == '1')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'C')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'E')
		|| (so_long->map[so_long->mobs[i].mob_y] \
			[so_long->mobs[i].mob_x] == 'M'))
		so_long->mobs[i].mob_x = so_long->mobs[i].mob_x - 1;
	else if (so_long->map[so_long->mobs[i].mob_y] \
		[so_long->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else
	{
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] = 'M';
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x - 1] = '0';
	}
	draw_map(so_long);
	draw_map_mobs(so_long);
}

void	update_mob_s(t_so_long *so_long, int i)
{
	update_mob_img('s', so_long);
	if ((so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == '1')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'C')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'E')
		|| (so_long->map[so_long->mobs[i].mob_y] \
			[so_long->mobs[i].mob_x] == 'M'))
		so_long->mobs[i].mob_y = so_long->mobs[i].mob_y - 1;
	else if (so_long->map[so_long->mobs[i].mob_y] \
		[so_long->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else
	{
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] = 'M';
		so_long->map[so_long->mobs[i].mob_y - 1][so_long->mobs[i].mob_x] = '0';
	}
	draw_map(so_long);
	draw_map_mobs(so_long);
}

void	update_mob_a(t_so_long *so_long, int i)
{
	update_mob_img('a', so_long);
	if ((so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == '1')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'C')
		|| (so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] == 'E')
		|| (so_long->map[so_long->mobs[i].mob_y] \
			[so_long->mobs[i].mob_x] == 'M'))
		so_long->mobs[i].mob_x = so_long->mobs[i].mob_x + 1;
	else if (so_long->map[so_long->mobs[i].mob_y] \
		[so_long->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else
	{
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x] = 'M';
		so_long->map[so_long->mobs[i].mob_y][so_long->mobs[i].mob_x + 1] = '0';
	}
	draw_map(so_long);
	draw_map_mobs(so_long);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:00:54 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/07 13:52:47 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_player_img(char key, t_so_long *so_long)
{
	if (key == 'w')
		so_long->img_player = so_long->img_player_back;
	else if (key == 'd')
		so_long->img_player = so_long->img_player_right;
	else if (key == 's')
		so_long->img_player = so_long->img_player_front;
	else if (key == 'a')
		so_long->img_player = so_long->img_player_left;
}

void	update_player_w(t_so_long *so_long)
{
	update_player_img('w', so_long);
	if (((so_long->map[so_long->player_y][so_long->player_x] == 'E')
		&& (so_long->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY, 1);
		game_exit(so_long);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else if ((so_long->map[so_long->player_y][so_long->player_x] == '1')
		|| (so_long->map[so_long->player_y][so_long->player_x] == 'E'))
		so_long->player_y = so_long->player_y + 1;
	else
	{
		if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
			so_long->nb_collect = so_long->nb_collect - 1;
		so_long->map[so_long->player_y][so_long->player_x] = 'P';
		so_long->map[so_long->player_y + 1][so_long->player_x] = '0';
		so_long->moves++;
		draw_map(so_long);
	}
}

void	update_player_d(t_so_long *so_long)
{
	update_player_img('d', so_long);
	if (((so_long->map[so_long->player_y][so_long->player_x] == 'E')
		&& (so_long->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY, 1);
		game_exit(so_long);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else if ((so_long->map[so_long->player_y][so_long->player_x] == '1')
		|| (so_long->map[so_long->player_y][so_long->player_x] == 'E'))
		so_long->player_x = so_long->player_x - 1;
	else
	{
		if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
			so_long->nb_collect = so_long->nb_collect - 1;
		so_long->map[so_long->player_y][so_long->player_x] = 'P';
		so_long->map[so_long->player_y][so_long->player_x - 1] = '0';
		so_long->moves++;
		draw_map(so_long);
	}
}

void	update_player_s(t_so_long *so_long)
{
	update_player_img('s', so_long);
	if (((so_long->map[so_long->player_y][so_long->player_x] == 'E')
		&& (so_long->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY, 1);
		game_exit(so_long);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else if ((so_long->map[so_long->player_y][so_long->player_x] == '1')
		|| (so_long->map[so_long->player_y][so_long->player_x] == 'E'))
		so_long->player_y = so_long->player_y - 1;
	else
	{
		if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
			so_long->nb_collect = so_long->nb_collect - 1;
		so_long->map[so_long->player_y][so_long->player_x] = 'P';
		so_long->map[so_long->player_y - 1][so_long->player_x] = '0';
		so_long->moves++;
		draw_map(so_long);
	}
}

void	update_player_a(t_so_long *so_long)
{
	update_player_img('a', so_long);
	if (((so_long->map[so_long->player_y][so_long->player_x] == 'E')
		&& (so_long->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY, 1);
		game_exit(so_long);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT, 1);
		game_exit(so_long);
	}
	else if ((so_long->map[so_long->player_y][so_long->player_x] == '1')
		|| (so_long->map[so_long->player_y][so_long->player_x] == 'E'))
		so_long->player_x = so_long->player_x + 1;
	else
	{
		if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
			so_long->nb_collect = so_long->nb_collect - 1;
		so_long->map[so_long->player_y][so_long->player_x] = 'P';
		so_long->map[so_long->player_y][so_long->player_x + 1] = '0';
		so_long->moves++;
		draw_map(so_long);
	}
}

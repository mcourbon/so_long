/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:54 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/18 13:43:02 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	events_player(int keycode, t_so_long *so_long)
{
	if (keycode == KEY_W || keycode == ARROW_UP)
	{
		so_long->player_y = so_long->player_y - 1;
		update_player_w(so_long);
	}
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
	{
		so_long->player_x = so_long->player_x - 1;
		update_player_a(so_long);
	}
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
	{
		so_long->player_y = so_long->player_y + 1;
		update_player_s(so_long);
	}
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
	{
		so_long->player_x = so_long->player_x + 1;
		update_player_d(so_long);
	}
	else if (keycode == KEY_Q || keycode == ESC)
		game_exit(so_long);
}

static void	events_mob(int keycode, t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->nb_mobs)
	{
		if (keycode == KEY_W || keycode == ARROW_UP)
		{
			so_long->mobs[i].mob_y = so_long->mobs[i].mob_y - 1;
			update_mob_w(so_long, i);
		}
		else if (keycode == KEY_S || keycode == ARROW_DOWN)
		{
			so_long->mobs[i].mob_y = so_long->mobs[i].mob_y + 1;
			update_mob_s(so_long, i);
		}
		i++;
	}
}

static void	events_mob_2(int keycode, t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->nb_mobs)
	{
		if (keycode == KEY_A || keycode == ARROW_LEFT)
		{
			so_long->mobs[i].mob_x = so_long->mobs[i].mob_x - 1;
			update_mob_a(so_long, i);
		}
		else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		{
			so_long->mobs[i].mob_x = so_long->mobs[i].mob_x + 1;
			update_mob_d(so_long, i);
		}
		i++;
	}
}

static int	key_press(int keycode, t_so_long *so_long)
{
	events_player(keycode, so_long);
	if (check_mobs(so_long->map))
	{
		events_mob(keycode, so_long);
		events_mob_2(keycode, so_long);
	}
	update_movements(so_long);
	return (0);
}

void	game_update(t_so_long *so_long)
{
	mlx_key_hook(so_long->win, key_press, so_long);
	mlx_hook(so_long->win, 17, 0, game_exit, so_long);
}

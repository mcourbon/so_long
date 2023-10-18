/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:34:12 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/10 15:59:18 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	init_img(t_so_long *so_long)
{
	so_long->img_grass = mlx_xpm_file_to_image
		(so_long->mlx, "asset/floor.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_wall = mlx_xpm_file_to_image
		(so_long->mlx, "asset/wall.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_player_front = mlx_xpm_file_to_image
		(so_long->mlx, "asset/front.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_player_right = mlx_xpm_file_to_image
		(so_long->mlx, "asset/right.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_player_back = mlx_xpm_file_to_image
		(so_long->mlx, "asset/back.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_player_left = mlx_xpm_file_to_image
		(so_long->mlx, "asset/left.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_collect_left = mlx_xpm_file_to_image
		(so_long->mlx, "asset/gem_left.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_collect_right = mlx_xpm_file_to_image
		(so_long->mlx, "asset/gem_right.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_exit_close = mlx_xpm_file_to_image
		(so_long->mlx, "asset/chest.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_exit_open = mlx_xpm_file_to_image
		(so_long->mlx, "asset/chst_open.xpm", &so_long->img_w, &so_long->img_h);
	return (0);
}

static int	init_img_mobs(t_so_long *so_long)
{
	int	i;

	i = -1;
	so_long->img_mob_front = mlx_xpm_file_to_image
		(so_long->mlx, "asset/mob_front.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_mob_right = mlx_xpm_file_to_image
		(so_long->mlx, "asset/mob_right.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_mob_back = mlx_xpm_file_to_image
		(so_long->mlx, "asset/mob_back.xpm", &so_long->img_w, &so_long->img_h);
	so_long->img_mob_left = mlx_xpm_file_to_image
		(so_long->mlx, "asset/mob_left.xpm", &so_long->img_w, &so_long->img_h);
	so_long->nb_mobs = check_nb_mobs(so_long);
	if (so_long->nb_mobs > 0)
	{
		so_long->mobs = malloc(sizeof(t_mob) * so_long->nb_mobs);
		if (so_long->mobs == NULL)
			return (-1);
		while (++i < so_long->nb_mobs)
			so_long->mobs[i].img_mob = so_long->img_mob_front;
	}
	return (0);
}

static int	load_img(t_so_long *so_long)
{
	init_img(so_long);
	if (init_img_mobs(so_long) == -1)
		return (-1);
	return (0);
}

static void	set_win_size(t_so_long *so_long)
{
	int	nb_columns;
	int	nb_lines;

	nb_lines = 0;
	nb_columns = ft_strlen(so_long->map[0]);
	so_long->map_w = nb_columns * 32;
	while (so_long->map[nb_lines])
		nb_lines++;
	so_long->map_h = nb_lines * 32;
}

int	game_load(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		return (0);
	set_win_size(so_long);
	so_long->win = mlx_new_window(so_long->mlx, \
		so_long->map_w, so_long->map_h, "so_long");
	if (!so_long->win)
		return (mlx_destroy_display(so_long->mlx), 1);
	so_long->moves = 0;
	if (load_img(so_long) == -1)
		return (-1);
	so_long->img_player = so_long->img_player_front;
	so_long->img_exit = so_long->img_exit_close;
	so_long->img_collect = so_long->img_collect_left;
	draw_map(so_long);
	draw_map_mobs(so_long);
	return (0);
}

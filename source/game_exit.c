/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:29:21 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/07 13:55:32 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	destroy_img(t_so_long *so_long)
{
	mlx_destroy_image(so_long->mlx, so_long->img_grass);
	mlx_destroy_image(so_long->mlx, so_long->img_wall);
	mlx_destroy_image(so_long->mlx, so_long->img_player_front);
	mlx_destroy_image(so_long->mlx, so_long->img_player_right);
	mlx_destroy_image(so_long->mlx, so_long->img_player_back);
	mlx_destroy_image(so_long->mlx, so_long->img_player_left);
	mlx_destroy_image(so_long->mlx, so_long->img_collect_right);
	mlx_destroy_image(so_long->mlx, so_long->img_collect_left);
	mlx_destroy_image(so_long->mlx, so_long->img_exit_close);
	mlx_destroy_image(so_long->mlx, so_long->img_exit_open);
	mlx_destroy_image(so_long->mlx, so_long->img_mob_front);
	mlx_destroy_image(so_long->mlx, so_long->img_mob_right);
	mlx_destroy_image(so_long->mlx, so_long->img_mob_back);
	mlx_destroy_image(so_long->mlx, so_long->img_mob_left);
	return (0);
}

int	game_exit(t_so_long *so_long)
{
	free_map(so_long->map);
	destroy_img(so_long);
	if (so_long->nb_mobs > 0)
		free(so_long->mobs);
	mlx_destroy_window(so_long->mlx, so_long->win);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:59:17 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/07 13:39:59 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_mobs(t_so_long *so_long, int x, int y, int mob_index)
{
	so_long->mobs[mob_index].mob_x = x;
	so_long->mobs[mob_index].mob_y = y;
}

int	draw_map_mobs(t_so_long *so_long)
{
	int	x;
	int	y;
	int	m;

	y = 0;
	m = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'M')
			{
				draw_mobs(so_long, x, y, m);
				draw_img(so_long, so_long->mobs[m].img_mob, x, y);
				m++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

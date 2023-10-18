/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:38:07 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/12 11:17:15 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	set_map_path(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'x' || map[x][y] == 'M')
		return (0);
	else if (map[x][y] != '1' || map[x][y] != 'x' || map[x][y] != 'M')
	{
		map[x][y] = 'x';
		set_map_path(map, x + 1, y);
		set_map_path(map, x - 1, y);
		set_map_path(map, x, y + 1);
		set_map_path(map, x, y - 1);
	}
	return (0);
}

static int	check_collect(char **map, int x, int y)
{
	set_map_path(map, x, y);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E' || map[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	check_path(char *file)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = read_map(file);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (check_collect(map, i, j) == 1)
					return (free_map(map), 0);
				else
					return (free_map(map), 1);
			}
			j++;
		}
		i++;
	}
	return (free_map(map), 1);
}

int	check_solution(char *file)
{
	if (!check_path(file))
	{
		ft_putendl_fd(NOT_SOLVABLE, 2);
		return (0);
	}
	return (1);
}

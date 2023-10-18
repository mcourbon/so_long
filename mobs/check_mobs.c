/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:03:46 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/05 11:53:39 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_mobs(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nb_mobs(t_so_long *so_long)
{
	int	i;
	int	j;
	int	nb_mobs;

	i = 0;
	nb_mobs = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'M')
				nb_mobs++;
			j++;
		}
		i++;
	}
	return (nb_mobs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:27:34 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/07 14:31:34 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_is_rectangle(char **map)
{
	int	i;
	int	len_lines;

	if (!map)
		return (0);
	i = 0;
	len_lines = 0;
	while (map[len_lines])
		len_lines++;
	if (len_lines < 2)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_walled(char **map)
{
	int	i;
	int	j;
	int	len_lines;
	int	len_columns;

	j = 0;
	len_lines = 0;
	while (map[len_lines])
		len_lines++;
	while (map[0][j] && map[len_lines - 1][j])
	{
		if (map[0][j] != '1' || map[len_lines - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len_columns = ft_strlen(map[i]);
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][len_columns - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_cep(t_so_long *so_long)
{
	int	i;
	int	j;

	so_long->nb_collect = 0;
	so_long->nb_exit = 0;
	so_long->nb_p = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				so_long->nb_collect++;
			else if (so_long->map[i][j] == 'E')
				so_long->nb_exit++;
			else if (so_long->map[i][j] == 'P')
				so_long->nb_p++;
			j++;
		}
		i++;
	}
	if (so_long->nb_collect == 0 || so_long->nb_exit != 1 || so_long->nb_p != 1)
		return (0);
	return (1);
}

static int	check_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_map(t_so_long *so_long)
{
	if (!check_is_rectangle(so_long->map))
	{
		ft_putendl_fd(NOT_RECTANGLE, 2);
		return (0);
	}
	if (!check_is_walled(so_long->map))
	{
		ft_putendl_fd(NOT_WALLED, 2);
		return (0);
	}
	if (!check_is_cep(so_long))
	{
		ft_putendl_fd(NOT_CEP, 2);
		return (0);
	}
	if (!check_is_valid(so_long->map))
	{
		ft_putendl_fd(NOT_VALID, 2);
		return (0);
	}
	return (1);
}

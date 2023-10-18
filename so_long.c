/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:12:53 by mcourbon          #+#    #+#             */
/*   Updated: 2023/10/11 13:16:59 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_if_ber(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
		&& av[i - 3] == '.')
		return (1);
	ft_putendl_fd(NOT_BER, 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_so_long	so_long;

	if (ac != 2)
	{
		ft_putendl_fd("Wrong number of arguments.", 2);
		exit(EXIT_FAILURE);
	}
	so_long.map = read_map(av[1]);
	if (so_long.map == NULL)
		exit(EXIT_FAILURE);
	if (check_if_ber(av[1]) && check_is_map(&so_long)
		&& check_solution(av[1]))
	{
		if (game_load(&so_long) == -1)
			exit(EXIT_FAILURE);
		game_update(&so_long);
		mlx_loop(so_long.mlx);
	}
	else
	{
		if (so_long.map != NULL)
			free_map(so_long.map);
		exit(EXIT_FAILURE);
	}
	return (0);
}

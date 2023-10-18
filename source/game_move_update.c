/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:59:03 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/05 11:50:24 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_movements(t_so_long *so_long)
{
	char	*tmp;

	tmp = ft_itoa(so_long->moves);
	mlx_string_put(so_long->mlx, so_long->win, 10, 10, 0x00FFFFFF, tmp);
	free(tmp);
	return (0);
}

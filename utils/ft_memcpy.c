/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:08:58 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/07 14:09:18 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	return (dest);
}

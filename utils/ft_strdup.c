/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:21 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/07 13:51:37 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		lenght;
	char	*duplicata;

	i = 0;
	lenght = ft_strlen(src);
	duplicata = malloc(sizeof(char) * (lenght + 1));
	if (duplicata == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		duplicata[i] = src[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:09:55 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/07 14:10:11 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mystr;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mystr = malloc((sizeof(char) * (len_s1 + len_s2 + 1)));
	if (mystr == NULL)
		return (NULL);
	ft_memcpy(mystr, s1, len_s1);
	ft_memcpy(mystr + len_s1, s2, len_s2);
	mystr[len_s1 + len_s2] = '\0';
	return (mystr);
}

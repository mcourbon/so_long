/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:01:24 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/07 14:02:25 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_digit(long nb)
{
	int		count;

	count = 0;
	if (nb == 0)
		count++;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*mystr;
	int		len;
	long	temp;

	temp = n;
	len = count_digit(temp);
	mystr = malloc(sizeof(char) * len + 1);
	if (mystr == NULL)
		return (NULL);
	mystr[len] = '\0';
	if (temp == 0)
		mystr[0] = '0';
	if (temp < 0)
	{
		mystr[0] = '-';
		temp = temp * (-1);
	}
	while (temp > 0)
	{
		mystr[--len] = '0' + temp % 10;
		temp = temp / 10;
	}
	return (mystr);
}

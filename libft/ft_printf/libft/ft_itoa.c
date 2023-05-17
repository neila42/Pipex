/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:56:28 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/09 16:10:52 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = len_n(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

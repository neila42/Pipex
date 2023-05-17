/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:35:11 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/01 14:58:43 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		if (s1[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:25:38 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/09 16:20:15 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != 0 && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (i + j < len && needle[j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == 0)
				return ((char *)(i + haystack));
		}
		i++;
	}
	return (NULL);
}

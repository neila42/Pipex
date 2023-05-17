/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:52:36 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/04 15:52:39 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*petit_s;
	size_t	size;
	size_t	size_s;

	size_s = ft_strlen(s);
	size = len;
	if (len > size_s - start)
		size = size_s - start;
	if (start >= size_s)
		size = 0;
	petit_s = malloc(size + 1);
	if (petit_s == 0)
		return (NULL);
	ft_memcpy(petit_s, s + start, size);
	petit_s[size] = '\0';
	return (petit_s);
}

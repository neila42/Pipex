/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:54:39 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/10 14:40:17 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < destlen)
		destlen = dstsize;
	if (destlen == dstsize)
		return (srclen + dstsize);
	if (srclen < dstsize - destlen)
		ft_memcpy(dst + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + destlen, src, dstsize - destlen - 1);
		dst[dstsize - 1] = 0;
	}
	return (srclen + destlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:55 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/09 16:18:35 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*s3;
	size_t			len_s3;
	size_t			len_s1;
	size_t			len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s3 = len_s1 + len_s2;
	s3 = malloc(len_s3 + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, len_s1);
	ft_memcpy(s3 + len_s1, s2, len_s2 + 1);
	return ((char *)(s3));
}

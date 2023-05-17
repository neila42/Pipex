/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:42:49 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/09 15:15:57 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_words(char const *s, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nbr++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nbr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		word_i;

	split = malloc((nbr_words(s, c) + 1) * sizeof (char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	word_i = -1;
	while (i <= ft_strlen(s))
	{
		if (word_i >= 0 && (i == ft_strlen(s) || s[i] == c))
		{
			split[j] = ft_substr(s, word_i, i - word_i);
			word_i = -1;
			j++;
		}
		else if (word_i == -1 && s[i] != c)
			word_i = i;
		i++;
	}
	split[j] = NULL;
	return (split);
}

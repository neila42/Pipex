/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:20:22 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/14 15:10:26 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *str)
{
	if (str == NULL)
		return (print_str("(null)"));
	ft_putstr_fd(str, 1);
	return ((int) ft_strlen(str));
}

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

int	print_int(int i)
{
	ft_putnbr_fd(i, 1);
	return (len_n(i));
}

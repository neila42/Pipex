/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:23:03 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/14 15:07:51 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	len_unsigned_n(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	print_unsigned_int_recur(unsigned int i)
{
	if (i > 9)
	{
		print_unsigned_int_recur(i / 10);
		print_unsigned_int_recur(i % 10);
	}
	else
		ft_putchar_fd(i + '0', 1);
}

int	print_unsigned_int(unsigned int i)
{
	print_unsigned_int_recur(i);
	return (len_unsigned_n(i));
}

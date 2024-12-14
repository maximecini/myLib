/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:50:24 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/14 13:44:41 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(int nb, int *i)
{
	long	number;

	number = nb;
	if (number < 0)
	{
		*i += 1;
		number *= -1;
		write(1, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_printf(number / 10, i);
	}
	*i += 1;
	ft_putchar_fd(ft_todigits(number % 10), 1);
}

void	ft_putnbr_base_printf(size_t number, char *base, int *i)
{
	unsigned int	lengt_base;

	lengt_base = valide_base(base);
	if (!lengt_base)
		return ;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number >= lengt_base)
	{
		ft_putnbr_base_printf(number / lengt_base, base, i);
	}
	*i += 1;
	ft_putchar_fd(base[number % lengt_base], 1);
}

int	ft_display_string(void *str, void (*f)(char *, int))
{
	if (!((char *)str))
		return (ft_putstr_fd("(null)", 1), 6);
	f((char *)str, 1);
	return (ft_strlen((char *)str));
}

int	ft_display_base(size_t number, char *str, void f(size_t, char *, int *))
{
	int	i;

	i = 0;
	if (!number)
		return (ft_putstr_fd("(nil)", 1), 5);
	if (number == 0)
		return (ft_putstr_fd("(null)", 1), 6);
	f(number, (char *)str, &i);
	return (i);
}

int	ft_display_uint(int number, void f(int, int *))
{
	int	i;

	i = 0;
	f(number, &i);
	return (i);
}

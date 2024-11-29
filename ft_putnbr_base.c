/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:19:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/10/03 18:35:20 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long	valide_base(char *base)
{
	long	i;
	long	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = 0;
		while (base[j])
		{	
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_cast_base(int i, char *base)
{	
	return (base[i]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	number;
	long	lengt_base;		

	lengt_base = valide_base(base);
	if (!lengt_base)
		return ;
	number = nbr;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number >= lengt_base)
	{
		ft_putnbr_base(number / lengt_base, base);
	}	
	ft_putchar(ft_cast_base(number % lengt_base, base));
}

int	main(int argc, char **argv)
{
	(void) argc;
	ft_putnbr_base(atoi(argv[1]), argv[2]);
}

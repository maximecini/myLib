/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:19:44 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 19:25:20 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/**
 * @brief Affiche un entier dans une base spécifiée.
 *
 * La fonction `ft_putnbr_base` prend un entier `n` et une base `base` (sous forme de chaîne de caractères)
 * et affiche la représentation de l'entier `n` dans cette base. 
 * Cette fonction prend en charge les bases de 2 à 16 et gère les entiers négatifs.
 * 
 * @param n L'entier à afficher.
 * @param base La base dans laquelle l'entier doit être affiché, sous forme de chaîne de caractères.
 *             Par exemple, pour la base 16, la chaîne peut être "0123456789ABCDEF".
 * 
 * @return Aucun retour (la fonction affiche directement le résultat).
 * 
 * @note La fonction ne gère pas les bases inférieures à 2 ou supérieures à 16.
 *       Elle utilise les chiffres et lettres pour les bases supérieures à 10.
 *       Si `n` est négatif, un signe '-' est affiché avant le nombre.
 */
size_t	ft_putnbr_base(int nbr, char *base)
{
	long	number;
	long	size_base;	
	long 	size_digit;
	long	curent;
	
	size_base = valide_base(base);
	if (!size_base)
		return 0 ;
	number = nbr;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	curent = ft_digitlen(number, size_base);
	size_digit = ft_base_power(number, size_base);
	if(nbr < 0)
		curent++;
	while (size_digit > 0)
	{	
		ft_putchar_fd(base[(number / size_digit) % size_base], 1);
		size_digit /= size_base;
	}
	return curent;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:56:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:13:36 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit un entier en chaîne de caractères.
 *
 * La fonction `itoa` prend un entier `n` et le convertit en une chaîne 
 * de caractères représentant ce nombre. La chaîne retournée est allouée 
 * dynamiquement et doit être libérée après utilisation. Cette fonction gère 
 * également les nombres négatifs.
 * 
 * @param n L'entier à convertir en chaîne de caractères.
 * 
 * @return La chaîne de caractères représentant l'entier, ou NULL 
 * 	si l'allocation échoue.
 * 
 * @note La fonction gère les entiers négatifs en ajoutant un signe '-' 
 * 	au début de la chaîne.La chaîne retournée doit être libérée manuellement 
 * 	après utilisation avec `free()`.
 */

char	*ft_itoa(int n)
{
	char		*str_number;
	long long	l;
	long long	number;

	number = (long long)n;
	if ((n < 0))
		number = -number;
	if (number == 0)
		return (ft_strdup("0"));
	l = ft_digitlen(n, 10);
	str_number = (char *)malloc((l + 1) * sizeof(char));
	if (!str_number)
		return (NULL);
	str_number[l--] = '\0';
	while (l >= 0)
	{
		str_number[l--] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		str_number[0] = '-';
	return (str_number);
}

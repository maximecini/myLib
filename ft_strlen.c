/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:10:50 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:39:22 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * La fonction `ft_strlen` parcourt la chaîne de caractères `s` et retourne le nombre de caractères
 * avant le caractère nul (`'\0'`), qui marque la fin de la chaîne. La fonction ne compte pas le caractère nul
 * lui-même, elle retourne uniquement la longueur de la partie visible de la chaîne.
 *
 * @param s La chaîne de caractères dont la longueur doit être calculée.
 * 
 * @return La longueur de la chaîne de caractères (nombre de caractères avant le caractère nul).
 * 
 * @note La fonction ne modifie pas la chaîne et elle est particulièrement utile pour travailler avec
 *       des chaînes de caractères en C, comme dans les opérations de copie, de concaténation, etc.
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

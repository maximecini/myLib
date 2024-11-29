/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:58:39 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:42:42 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islowercase(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * @brief Convertit un caractère en majuscule.
 *
 * La fonction `ft_toupper` prend un caractère en entrée et retourne sa version en majuscule si le caractère
 * est une lettre minuscule (a-z). Si le caractère est déjà en majuscule (A-Z) ou n'est pas une lettre,
 * la fonction retourne le caractère inchangé.
 *
 * @param c Le caractère à convertir.
 * 
 * @return Le caractère converti en majuscule, ou le caractère inchangé s'il est déjà en majuscule ou non alphabétique.
 * 
 * @note Cette fonction est équivalente à la fonction standard `toupper` de la bibliothèque C.
 */
int	ft_toupper(int c)
{
	if (ft_islowercase(c))
		return (c - ('a' - 'A'));
	return (c);
}

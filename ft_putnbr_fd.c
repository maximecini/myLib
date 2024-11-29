/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:53:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:36:04 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Écrit un entier sur un descripteur de fichier.
 *
 * La fonction `ft_putnbr_fd` convertit l'entier `n` en une chaîne de caractères et l'écrit
 * sur le descripteur de fichier donné (`fd`). Si l'entier est négatif, un signe `-` est écrit
 * avant le nombre. La fonction gère aussi les entiers zéro et les autres cas de manière appropriée.
 *
 * @param n L'entier à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire l'entier.
 * 
 * @return Aucune valeur de retour. L'entier est écrit directement sur le descripteur de fichier.
 * 
 * @note Cette fonction est souvent utilisée pour afficher des entiers dans des flux de sortie
 *       différents de `stdout`, comme `stderr`, ou pour écrire des entiers dans des fichiers.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number < 0)
	{
		number *= -1;
		ft_putchar_fd('-', fd);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	ft_putchar_fd(number % 10 + '0', fd);
}

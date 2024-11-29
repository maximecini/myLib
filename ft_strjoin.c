/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:09:32 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:38:15 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères.
 *
 * La fonction `ft_strjoin` prend deux chaînes de caractères `s1` et `s2`, et crée une nouvelle
 * chaîne qui est la concaténation des deux chaînes. La mémoire pour la nouvelle chaîne est allouée
 * dynamiquement. Si l'allocation échoue, la fonction retourne `NULL`. Le contenu de `s1` est suivi
 * de celui de `s2` dans la chaîne résultante. La chaîne résultante est terminée par un caractère nul
 * (`'\0'`).
 *
 * @param s1 La première chaîne de caractères à concaténer.
 * @param s2 La deuxième chaîne de caractères à concaténer.
 * 
 * @return Une nouvelle chaîne contenant la concaténation de `s1` et `s2`, ou `NULL` si l'allocation échoue.
 * 
 * @note La fonction alloue dynamiquement de la mémoire pour la chaîne résultante. Il est donc nécessaire
 *       de libérer cette mémoire une fois qu'elle n'est plus utilisée.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l = l_s1 + l_s2;
	dest = ((char *)malloc((l + 1) * sizeof(char)));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, l_s1 + 1);
	ft_strlcat(dest, s2, l + 1);
	return (dest);
}

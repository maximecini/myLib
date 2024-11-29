/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:50:38 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:36:52 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char ch)
{
	size_t	i;
	size_t	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != ch && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == ch)
			trigger = 0;
		str++;
	}
	return (i);
}

static void	ft_free_split(char **split, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		free(split[i]);
	free(split);
}

static char	**ft_to_write(char const *src, char c, char **split, size_t l_word)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (src[++i])
	{
		if (src[i] != c)
			l_word++;
		else if (src[i] == c && l_word > 0)
		{
			split[j] = ft_substr(src, (i - l_word), l_word);
			if (!split[j++])
				return (ft_free_split(split, j), NULL);
			l_word = 0;
		}
	}
	if (l_word > 0)
	{
		split[j++] = ft_substr(src, (i - l_word), l_word);
		if (!split[j - 1])
			return (ft_free_split(split, j - 1), NULL);
	}
	return (split[j] = NULL, split);
}

/**
 * @brief Divise une chaîne de caractères en sous-chaînes en fonction d'un séparateur.
 *
 * La fonction `ft_split` prend une chaîne de caractères `s` et un séparateur `c`, et divise
 * la chaîne en sous-chaînes. Elle retourne un tableau de chaînes, où chaque élément est une
 * sous-chaîne de `s` séparée par le caractère `c`. La fonction alloue dynamiquement de la mémoire
 * pour chaque sous-chaîne et le tableau retourné. Si une erreur d'allocation se produit, la fonction
 * libère toute la mémoire précédemment allouée et retourne `NULL`.
 *
 * @param s La chaîne de caractères à diviser.
 * @param c Le caractère séparateur utilisé pour diviser la chaîne.
 * 
 * @return Un tableau de sous-chaînes. Si l'allocation échoue, retourne `NULL`.
 * 
 * @note La fonction alloue dynamiquement la mémoire pour chaque sous-chaîne et pour le tableau.
 *       Il est donc important de libérer cette mémoire une fois qu'elle n'est plus utilisée.
 */

char	**ft_split(char const *src, char c)
{
	char	**split;

	split = (char **)malloc((ft_count_word(src, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_to_write(src, c, split, 0);
	return (split);
}

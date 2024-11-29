/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:26:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 16:21:18 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ajoute un élément à la fin d'une liste chaînée.
 *
 * La fonction `ft_lstadd_back` prend en entrée un pointeur vers un pointeur de tête de
 * liste chaînée (`lst`) et un pointeur vers le nouvel élément (`new`). Elle ajoute cet
 * élément à la fin de la liste existante. Si la liste est vide (c'est-à-dire si `lst` est
 * NULL), l'élément est ajouté comme premier élément de la liste.
 * 
 * @param lst Le pointeur vers le premier élément de la liste (tête de la liste).
 * @param new Le nouvel élément à ajouter à la fin de la liste.
 * 
 * @return Aucune valeur de retour. La liste est modifiée directement.
 * 
 * @note Si `lst` est NULL, l'élément `new` devient la tête de la liste.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	temp = ft_lstlast(temp);
	temp->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:47:04 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 19:10:06 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Supprime un élément spécifique d'une liste chaînée et libère la mémoire associée.
// @param lst L'élément de la liste à supprimer.
// @param del La fonction à appliquer pour supprimer le contenu de l'élément.
//  @return Aucune valeur de retour. L'élément est supprimé de la liste et la mémoire est libérée.
//  @note Cette version peut comporter des comportements supplémentaires,comme des vérifications
//   spécifiques ou des optimisations pour la suppression des éléments.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

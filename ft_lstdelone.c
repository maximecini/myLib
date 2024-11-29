/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:47:04 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:20:02 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Supprime et libère un élément d'une liste chaînée.
 *
 * La fonction `ft_lstdelone` prend en paramètre un élément d'une liste 
 * chaînée (de type `t_list`) et une fonction `del` qui est utilisée pour 
 * libérer le contenu de cet élément. La mémoire allouée pour l'élément est 
 * ensuite libérée. Le pointeur vers l'élément ne sera plus valide après l'appel.
 *
 * @param lst Un pointeur vers l'élément de la liste à supprimer.
 * @param del Une fonction pointeur utilisée pour libérer le contenu de 
 * 	l'élément.Cette fonction doit être définie par l'utilisateur et adaptée au 
 *
 * @return Aucun retour. La mémoire de l'élément `lst` est libéréents.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

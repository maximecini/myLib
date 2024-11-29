/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:46:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/29 20:21:56 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applique une fonction à chaque élément d'une liste chaînée.
 *
 * La fonction `ft_lstiter` prend en entrée un pointeur vers la tête 
 * d'une liste chaînée (`lst`) et une fonction de transformation (`f`). 
 * Elle parcourt la liste et applique la fonction`f` à chaque élément 
 * de la liste. Cette fonction ne modifie pas la structure de la liste, 
 * mais elle peut être utilisée pour appliquer des opérations ou des 
 * transformations sur les élémentsde la liste (par exemple, modification des 
 * données contenues dans chaque élément).
 * 
 * @param lst Le pointeur vers le premier élément de la liste.
 * @param f La fonction à appliquer à chaque élément de la liste.
 * 
 * @return Aucune valeur de retour. La liste est parcourue et la fonction `f` 
 * 	est appliquée chaque élément.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

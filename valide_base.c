/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:08:50 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/14 13:34:49 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	valide_base(char *base)
{
	long	i;
	long	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

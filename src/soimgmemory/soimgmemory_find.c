/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:17 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

t_somemdata	*soimgmemory_remove(t_solib *solib, void *ptr)
{
	t_somemdata	*current;
	t_somemdata	*tmp;

	if (!solib->so->imgmemory)
		return (NULL);
	current = solib->so->imgmemory->first;
	if ((unsigned long)current->ptr == (unsigned long)ptr)
	{
		solib->so->imgmemory->first = current->next;
		return (current);
	}
	while (current->next && current->next->ptr)
	{
		tmp = current->next;
		if ((unsigned long)current->next->ptr == (unsigned long)ptr)
		{
			current->next = current->next->next;
			return (tmp);
		}
		current = tmp;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:31 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:53:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	soimgmemory_clear(t_solib *solib)
{
	t_somemdata	*current;
	t_somemdata	*tmp;

	current = solib->so->imgmemory->first;
	solib->print("test ---- %p -- %p\n", current, current->ptr);
	while (current->ptr)
	{
		tmp = current->next;
		soimgfree(solib->so, current->ptr);
		current = tmp;
	}
	free(current);
	solib->so->imgmemory->first = NULL;
}

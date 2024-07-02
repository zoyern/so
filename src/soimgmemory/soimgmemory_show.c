/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:17:04 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:08:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	soimgmemory_show(t_solib *solib)
{
	t_somemdata	*current;

	current = solib->so->imgmemory->first;
	while (current)
	{
		solib->so->print("%p -> %CF26C29(%p)\t\tnext : %p\n",
			current, current->ptr, current->next);
		current = current->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 14:21:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	soimgmemory_add(t_solib *solib, void *ptr)
{
	t_somemdata	*memory;

	memory = (t_somemdata *)malloc(sizeof(t_somemdata));
	if (!memory)
		solib->close(solib, EXIT_FAILURE);
	memory->ptr = ptr;
	memory->next = solib->so->imgmemory->first;
	solib->so->imgmemory->first = memory;
}

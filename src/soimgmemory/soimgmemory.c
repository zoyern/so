/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgmemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:35:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	soimgmemory_close(t_solib *solib)
{
	if (!solib->so)
		return ;
	if (!solib->so->imgmemory)
		return ;
	if (!solib->so->imgmemory->first)
		return (free(solib->so->imgmemory));
	solib->so->imgmemory->clear(solib->so->solib);
	free(solib->so->imgmemory);
	solib->so->imgmemory = NULL;
}

int	soimgnew_memory(t_so *so)
{
	so->imgmemory = (t_somemory *)malloc(sizeof(t_somemory));
	if (!so->imgmemory)
		return (so->solib->free(so->solib, so), 1);
	so->imgmemory->show = soimgmemory_show;
	so->imgmemory->remove = soimgmemory_remove;
	so->imgmemory->clear = soimgmemory_clear;
	so->imgmemory->add = soimgmemory_add;
	so->imgmemory->close = soimgmemory_close;
	so->imgmemory->first = (t_somemdata *)malloc(sizeof(t_somemdata));
	so->imgmemory->first->ptr = NULL;
	so->imgmemory->first->next = NULL;
	return (0);
}

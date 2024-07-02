/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soimgfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:45 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

int	soimgfree(t_so *so, void *ptr)
{
	t_somemdata	*memory;

	if (!ptr)
		return (0);
	if (!so)
		return (free(ptr), 1);
	memory = soimgmemory_remove(so->solib, ptr);
	if (!memory)
		return (0);
	mlx_destroy_image(so->mlx, memory->ptr);
	memory->ptr = NULL;
	free(memory);
	memory = NULL;
	return (1);
}

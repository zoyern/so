/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:08:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/05 18:08:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	collider_list_add(t_so *so, t_sosprite *sprite, int enabled,
		int (*callback)())
{
	t_socollider	*collider;

	collider = so->malloc(so, sizeof(t_socollider));
	collider->sprite = sprite;
	collider->transform = sprite->transform;
	collider->callback = callback;
	collider->enabled = enabled;
	collider->next = so->colliders->first;
	so->colliders->first = collider;
	sprite->collider = collider;
}

void	collider_list_clear(t_so *so, t_socolliders_list *list)
{
	t_socollider	*box;
	t_socollider	*tmp;

	if (!list)
		return ;
	box = list->first;
	while (box)
	{
		tmp = box->next;
		so->free(so, box);
		box = tmp;
	}
	so->free(so, list);
	list = NULL;
}

void	sonew_collider(t_so *so)
{
	if (!so)
		return ;
	so->colliders = so->malloc(so, sizeof(t_socolliders_list));
	so->colliders->first = so->malloc(so, sizeof(t_socollider));
	so->colliders->first->transform = NULL;
	so->colliders->first->sprite = NULL;
	so->colliders->first->next = NULL;
}

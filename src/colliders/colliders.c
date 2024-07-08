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

void	collider_list_add(t_so *so, t_sosprite *sprite, int enabled, int (*callback)())
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

void	so_vec2_add(t_so *so, t_sovec2 *dest, t_sovec2 vec2)
{
	if (!dest || !so)
		return ;
	dest->x += vec2.x;
	dest->y += vec2.y;
}

void	so_move_and_check(t_so *so, t_sovec2 vec2, t_sosprite *sprite)
{
	t_socollider	*collider;
	t_sovec2		new_vec2;
	int				ret;

	collider = so->colliders->first;
	ret = 0;
	new_vec2.x = sprite->collider->transform->origin->x + vec2.x;
	new_vec2.y = sprite->collider->transform->origin->y + vec2.y;
	while (collider && collider->transform)
	{
		if ( collider->enabled && collider != sprite->collider
					&& is_inside(*collider->transform->origin, *collider->transform->size, new_vec2, *sprite->collider->transform->size))
			{
				if (collider->callback)
				{
					if (collider->callback(so, so->data, collider, sprite->collider))
						so->close(so, EXIT_FAILURE);
					ret++;
				}
				if (sprite->collider->callback)
				{
					if (sprite->collider->callback(so, so->data, sprite->collider, collider))
						so->close(so, EXIT_FAILURE);
					ret++;
				}

			}
		collider = collider->next;
	}
	if (!ret)
		so_vec2_add(so, sprite->transform->origin, vec2);
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
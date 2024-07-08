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

void	collider_list_free(t_so *so, t_socolliders_list *list, t_socollider *collider)
{
	t_socollider	*box;
	t_socollider	*tmp;
	(void)collider;

	if (!list)
		return ;
	box = list->first;
	while (box)
	{
		//if (so->libft->strncmp(collider->sprite->construct->name, box->sprite->construct->name, so->libft->strlen(box->sprite->construct->name)))
		tmp = box->next;
		so->free(so, box);
		box = tmp;
	}
	so->free(so, list);
	list = NULL;
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

void	collider_list_show(t_so *so)
{
	t_socollider	*collider;

	so->print("colliders show\n\n\n\n");
	if (!so || !so->colliders || !so->colliders->first)
		return ;
	collider = so->colliders->first;
	if (!collider)
		return ;
	while (collider->transform)
	{
		so->print("%p -- %d-%d | %d-%d\n", collider, (int)collider->transform->origin->x, (int)collider->transform->origin->y, (int)collider->transform->origin->x + collider->transform->size->width, (int)collider->transform->origin->y + collider->transform->size->height);
		collider = collider->next;
	}
}


int is_inside(t_sovec2 A, t_sosize A_size, t_sovec2 B, t_sosize B_size)
{
    return (B.x + B_size.width >= A.x + 5 &&
            B.y + B_size.height >= A.y +  5 &&
            B.x <= A.x + A_size.width - 5 &&
            B.y <= A.y + A_size.height - 5);
}


void	so_vec2_add(t_so *so, t_sovec2 *dest, t_sovec2 vec2)
{
	if (!dest || !so)
		return ;
	dest->x += vec2.x;
	dest->y += vec2.y;
}

#include <stdio.h>

void	so_move_and_check(t_so *so, t_sovec2 vec2, t_sosprite *sprite)
{
	t_socollider	*collider;
	t_sovec2		new_vec2;
	int				ret;

	//j'ai besoin de check si le vecteur est dans 
	collider = so->colliders->first;
	ret = 0;
	new_vec2.x = sprite->collider->transform->origin->x + vec2.x;
	new_vec2.y = sprite->collider->transform->origin->y + vec2.y;
	//printf("%f -- %f\n", new_vec2.x, new_vec2.y);
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
	//so->print("%d callback call\n", ret);
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
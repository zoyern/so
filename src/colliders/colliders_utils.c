/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliders_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:10:13 by marvin            #+#    #+#             */
/*   Updated: 2024/07/08 20:10:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

int	is_inside(t_sovec2 A, t_sosize A_size, t_sovec2 B, t_sosize B_size)
{
	return (B.x + B_size.width >= A.x
		&& B.y + B_size.height >= A.y
		&& B.x <= A.x + A_size.width
		&& B.y <= A.y + A_size.height);
}

void	so_vec2_add(t_so *so, t_sovec2 *dest, t_sovec2 vec2)
{
	if (!dest || !so)
		return ;
	dest->x += vec2.x;
	dest->y += vec2.y;
}

int	so_collider_call_callback(t_so *so, t_socollider *collider,
		t_socollider *sprite)
{
	int	ret;

	ret = 0;
	if (collider->callback)
	{
		if (collider->callback(so, so->data, collider, sprite))
			so->close(so, EXIT_FAILURE);
		ret++;
	}
	if (sprite->callback)
	{
		if (sprite->callback(so, so->data, sprite, collider))
			so->close(so, EXIT_FAILURE);
		ret++;
	}
	return (ret);
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
		if (collider->enabled && collider != sprite->collider
			&& is_inside(*collider->transform->origin,
				*collider->transform->size, new_vec2,
				*sprite->collider->transform->size))
			ret += so_collider_call_callback(so, collider, sprite->collider);
		collider = collider->next;
	}
	if (!ret)
		so_vec2_add(so, sprite->transform->origin, vec2);
}

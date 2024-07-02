/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gears_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:02:15 by zoyern            #+#    #+#             */
/*   Updated: 2024/06/12 22:42:03 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

t_sosize *so_size(t_solib *solib, float width, float height)
{
	t_sosize *size;

	size = (t_sosize *)solib->malloc(solib, sizeof(t_sosize));
	size->width = width;
	size->height = height;
	return (size);
}

t_sovec2 *so_vec2(t_solib *solib, float x, float y)
{
	t_sovec2 *vector2;

	vector2 = (t_sovec2 *)solib->malloc(solib, sizeof(t_sovec2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}

t_sotransform *so_transform(t_solib *solib, t_sovec2 *vector2, t_sosize *size)
{
	t_sotransform *transform;

	transform = (t_sotransform *)solib->malloc(solib, sizeof(t_sotransform));
	transform->origin = vector2;
	transform->size = size;
	return (transform);
}

t_soconstruct *so_construct(t_solib *solib, char *name, char *args, int enabled)
{
	t_soconstruct *construct;

	construct = (t_soconstruct *)solib->malloc(solib, sizeof(t_soconstruct));
	construct->name = name;
	construct->args = args;
	construct->enabled = enabled;
	return (construct);
}

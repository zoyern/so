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
#include <sotypes/soprintf.h>

void	so_put_images_list(t_sosprite *area, t_sosprite_list *list)
{
	t_sosprite_box	*box;

	if (!list || !area)
		return ;
	box = list->first;
	while (box->current)
	{
		so_put_on_grid(area, box->current);
		box = box->next;
	}
}

void	so_put_grid(t_so *so)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!so || !so->grid)
		return ;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			so_put_on_grid(so->area, so->grid->area[i][j]);
			j++;
		}
		i++;
	}
	so_put_images_list(so->area, so->grid->list);
}

void	so_set_background(t_so *so, char *color, t_sosize *size)
{
	so->new->grid(so, 1, 1);
	so->area = so->new->sprite(so,
			so->construct(so,
				"background", color, TRUE),
			so->transform(so,
				so->vec2(so, 0, 0),
				so->size(so, size->width, size->height)));
	so->grid->background(so, 0, so->area, NULL);
}

int	so_render(t_so *so)
{
	so_cpy_image(so, so->area->data, so->area->origin);
	so_put_grid(so);
	mlx_put_image_to_window(so->mlx, so->window, so->area->data->ptr, 0, 0);
	return (0);
}

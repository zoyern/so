/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	so_free_grid(t_so *so)
{
	if (!so->grid)
		return ;
	int	i = 0;
	int j = 0;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			if (so->grid->area[i][j]->origin)
				soimgfree(so, so->grid->area[i][j]->origin->ptr);
			if (so->grid->area[i][j]->data)
				soimgfree(so, so->grid->area[i][j]->data->ptr);
			so->free(so, so->grid->area[i][j]->construct);
			so->free(so, so->grid->area[i][j]->transform);
			so->free(so, so->grid->area[i][j]);
			j++;
		}
		so->free(so, so->grid->area[i]);
		i++;
	}
	so->free(so, so->grid);
}

void	so_show_grid(t_so *so)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!so->grid)
		return ;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			so->print("(%p-%p),", so->grid->area[i][j]->origin, so->grid->area[i][j]->data);
			j++;
		}
		so->print("\n");
		i++;
	}
}

void	so_grid(t_so *so, int width, int height)
{
	int i;
	int j;

	i = 0;
	j = 0;
	so->print("grided :) %d -- %d\n", width, height);
	if (so->grid)
		so->grid->close(so);
	so->grid = so->malloc(so, sizeof(t_sogrid));
	so->grid->width = width;
	so->grid->height = height;
	so->grid->raw = so->canva->width / width;
	so->grid->collum = so->canva->height / height;
	so->grid->background = so_grid_add_background;
	so->grid->close = so_free_grid;
	so->grid->show = so_show_grid;
	so->print("w x h : %d - %d | raw : %d -- collum %d\n", so->grid->width, so->grid->height, so->grid->raw, so->grid->collum);
	so->grid->area = so->malloc(so, sizeof(t_sosprite **) * (height));
	while (i < height)
	{
		j = 0;
		so->grid->area[i] = so->malloc(so, sizeof(t_sosprite *) * (width));
		while (j < width)
		{
			so->grid->area[i][j]  = so->new->sprite(so, so->construct(so,
				"grid", NULL, TRUE), so->transform(so,
				so->vec2(so, j * so->grid->raw, i * so->grid->collum),
				so->size(so, so->grid->raw, so->grid->collum)));
			j++;
		}
		i++;
	}
}

void	so_grid_add_background(t_so *so, char c, t_sosprite *sprite, char **map)
{
	int y;
	int x;

	if (!so->grid)
		return ;
	y = 0;

	while (y < so->grid->height)
	{
		x = 0;
		while (x < so->grid->width)
		{
			//printf(" - so->grid->area[%d][%d]  -- %f -- %f | %d -- %d\n", y, x, so->grid->area[y][x]->transform->origin->x, so->grid->area[y][x]->transform->origin->y, so->grid->area[y][x]->transform->size->width, so->grid->area[y][x]->transform->size->height);
			if (map && map[y][x] == c)
			{
				//copy plutot que creer un nouveau
				//so->grid->area[y][x]->origin = sprite->origin;
				if (sprite->origin)
					so_cpy_image(so, so->grid->area[y][x]->origin, sprite->origin);
				else
					so_cpy_image(so, so->grid->area[y][x]->origin, sprite->data);
				so_cpy_image(so, so->grid->area[y][x]->data, sprite->data);
				//printf("so->grid->area[i][j] -- %d -- %d\n", j, i);
				//printf(" - so->grid->area[i][j]  -- %f -- %f | %d -- %d\n",  so->grid->area[i][j]->transform->origin->x, so->grid->area[i][j]->transform->origin->y, so->grid->area[i][j]->transform->size->width, so->grid->area[i][j]->transform->size->height);
				
				//printf(" - %c -so->grid->area[i][j] %c -- %f -- %f\n",c, map[i][j],  so->grid->area[i][j]->transform->origin->x, so->grid->area[i][j]->transform->origin->y);
				so->grid->area[y][x]->construct->args = sprite->construct->args;
			}
			if (!map)
			{
				if (sprite->origin)
					so_cpy_image(so, so->grid->area[y][x]->origin, sprite->origin);
				so_cpy_image(so, so->grid->area[y][x]->data, sprite->data);
				so->grid->area[y][x]->construct->args = sprite->construct->args;
			
			}
			x++;
		}
		y++;
	}
}
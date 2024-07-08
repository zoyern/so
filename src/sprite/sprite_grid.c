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
	int	i;
	int	j;

	if (!so->grid)
		return ;
	i = 0;
	j = 0;
	if (so->grid->list)
		sprite_list_clear(so, so->grid->list);
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			if (so->grid->area[i][j]->origin)
				soimgfree(so, so->grid->area[i][j]->origin->ptr);
			if (so->grid->area[i][j]->data)
				soimgfree(so, so->grid->area[i][j]->data->ptr);
			if (so->grid->area[i][j]->collider)
			so->free(so, so->grid->area[i][j]->construct);
			so->free(so, so->grid->area[i][j]->transform);
			so->grid->area[i][j]->collider = NULL;
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!so->grid)
		return ;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			so->print("(%p-%p),", so->grid->area[i][j]->origin,
				so->grid->area[i][j]->data);
			j++;
		}
		so->print("\n");
		i++;
	}
}

t_sogrid	*so_grid_init(t_so *so, int width, int height)
{
	t_sogrid	*grid;

	grid = so->malloc(so, sizeof(t_sogrid));
	grid->width = width;
	grid->height = height;
	grid->raw = so->canva->width / width;
	grid->collum = so->canva->height / height;
	grid->size = so->size(so, grid->raw * width, grid->collum * height);
	grid->background = so_grid_add_background;
	grid->close = so_free_grid;
	grid->show = so_show_grid;
	return (grid);
}

void	so_grid(t_so *so, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (so->grid)
		so->grid->close(so);
	so->grid = so_grid_init(so, width, height);
	so->grid->list = sprite_list(so);
	so->grid->add = so_grid_add_list;
	so->grid->adds = so_grid_adds_list;
	so->grid->get = sprite_list_get;
	so->grid->gets = NULL;
	so->grid->area = so->malloc(so, sizeof(t_sosprite **) * (height));
	while (i < height && i < so->grid->height)
	{
		j = 0;
		so->grid->area[i] = so->malloc(so, sizeof(t_sosprite *) * (width));
		while (j < width && i < so->grid->width)
		{
			so->grid->area[i][j] = so->new->sprite(so, so->construct(so,
						"grid", NULL, TRUE), so->transform(so,
						so->vec2(so, j * so->grid->raw, i * so->grid->collum),
						so->size(so, so->grid->raw, so->grid->collum)));
			so->grid->area[i][j]->collider = NULL;
			j++;
		}
		i++;
	}
}

void	so_grid_add_background(t_so *so, char c, t_sosprite *sprite, char **map)
{
	int	y;
	int	x;

	if (!so->grid)
		return ;
	y = 0;
	while (y < so->grid->height)
	{
		x = 0;
		while (x < so->grid->width)
		{
			if (map && map[y][x] == c)
			{
				cpy_sprite(so, so->grid->area[y][x], sprite);
				if (sprite->collider)
					collider_list_add(so, so->grid->area[y][x], sprite->construct->enabled, sprite->collider->callback);
				else
					so->grid->area[y][x]->collider = NULL;
			}
			if (!map)
			{
				cpy_sprite(so, so->grid->area[y][x], sprite);
				if (sprite->collider)
					collider_list_add(so, so->grid->area[y][x], sprite->construct->enabled, sprite->collider->callback);
				else
					so->grid->area[y][x]->collider = NULL;
			}
			x++;
		}
		y++;
	}
}

void	so_grid_add_list(t_so *so, t_sosprite *sprite)
{
	if (!so->grid)
		return ;
	sprite_list_add(so, so->grid->list,
						sprite);
}

void	so_grid_adds_list(t_so *so, char c, t_sosprite *sprite, char **map)
{
	t_sosprite	*new_sprite;
	int	i;
	int	j;

	if (!so->grid)
		return ;
	i = 0;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			if (map && map[i][j] == c)
			{
				new_sprite = so->new->sprite(so,
				so->construct(so,
						sprite->construct->name, sprite->construct->args, sprite->construct->enabled),
				so->transform(so,
						so->vec2(so, (j * so->grid->raw) + (so->grid->raw/2) - (sprite->transform->size->width / 2), (i * so->grid->collum) + (so->grid->collum / 2) - (sprite->transform->size->height / 2)),
						so->size(so, sprite->transform->size->width, sprite->transform->size->width)));
				if (sprite->collider)
					collider_list_add(so, new_sprite, sprite->construct->enabled,  sprite->collider->callback);
				sprite_list_add(so, so->grid->list, new_sprite);
			}
			j++;
		}
		i++;
	}
}
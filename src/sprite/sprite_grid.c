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
	grid->list = sprite_list(so);
	grid->add = so_grid_add_list;
	grid->adds = so_grid_adds_list;
	grid->get = sprite_list_get;
	grid->gets = NULL;
	grid->area = so->malloc(so, sizeof(t_sosprite **) * (height));
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
				sprite_cpy_img_collider(so, so->grid->area[y][x], sprite);
			if (!map)
				sprite_cpy_img_collider(so, so->grid->area[y][x], sprite);
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
	int			i;
	int			j;

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
				new_sprite = so_center_sprite_on_grid(so, sprite, j, i);
				if (sprite->collider)
					collider_list_add(so, new_sprite,
						sprite->construct->enabled, sprite->collider->callback);
				sprite_list_add(so, so->grid->list, new_sprite);
			}
			j++;
		}
		i++;
	}
}

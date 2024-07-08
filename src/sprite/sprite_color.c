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

void	solib_fill_sprite_color(t_sosprite_data *data, char *color)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	if (!color || data)
		return ;
	c = so_get_color(color);
	if (c < 0)
		c = (int)0xFF000000;
	while (i < data->size->height)
	{
		j = 0;
		while (j < data->size->width)
		{
			solib_write_pixel(data, j, i, c);
			j++;
		}
		i++;
	}
}

void	so_cpy_image(t_so *so, t_sosprite_data *dest, t_sosprite_data *src)
{
	t_sovec2	*ratio;
	t_sovec2	*size_redem;
	int			i;
	int			j;

	if (!src || !dest)
		return ;
	ratio = calculate_ratio_size(so, dest, src, &size_redem);
	i = 0;
	while (i < dest->size->height)
	{
		j = 0;
		while (j < dest->size->width)
		{
			solib_write_all_pixel(dest, j, i,
				solib_get_pixel(src, j / ratio->x, i / ratio->y));
			j++;
		}
		i++;
	}
}

void	so_put_on_grid(t_so *so, t_sosprite *dest, t_sosprite *src)
{
	int	i;
	int	j;

	if (!src || !dest || !src->construct->enabled)
		return ;
	i = 0;
	j = 0;
	(void)so;
	//so->print("%d-%d | %d-%d ---- %d-%d | %d-%d\n", (int)src->transform->origin->x, (int)src->transform->origin->y, src->transform->size->width, dest->transform->size->height,  (int)dest->transform->origin->x, (int)dest->transform->origin->y, dest->transform->size->width, dest->transform->size->height);
	while (i < src->transform->size->height)
	{
		j = 0;
		while (j < src->transform->size->width)
		{

			if (i + (int)src->transform->origin->y >= (int)dest->transform->origin->y && i + (int)src->transform->origin->y <= dest->transform->size->height
					&& j + (int)src->transform->origin->x >= (int)dest->transform->origin->x && j + (int)src->transform->origin->x <= dest->transform->size->width)
				solib_write_pixel(dest->data, j + (int)src->transform->origin->x, i
					+ (int)src->transform->origin->y,
					solib_get_pixel(src->data, j, i));
				
			j++;
		}
		i++;
	}
}

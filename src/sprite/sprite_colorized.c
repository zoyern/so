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

void	solib_write_pixel(t_sosprite_data *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < data->size->width && y < data->size->height)
		dst = (data->adress + ((x + (y) * (data->size->width))
					* (data->bpp / 8)));
	*(unsigned int *)dst = color;
}

unsigned int	solib_get_pixel(t_sosprite_data *data, int x, int y)
{
	return (*(unsigned int *)(data->adress + ((x + (y)
				* (data->size->width)) * (data->bpp / 8))));
}

void	solib_fill_sprite_color(t_sosprite_data *data, char *color)
{
	int i;
	int j;
	int c;
	i = 0;
	c = solib_convert_color(color);
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

t_sovec2	*calculate_ratio_size(t_so *so, t_sosprite_data *dest, t_sosprite_data *src, t_sovec2 **out)
{
	t_sovec2 *ratio;
	ratio = so->vec2(so,
		(float)dest->size->width / (float)src->size->width,
		(float)dest->size->height / (float)src->size->height);
	*out = so->vec2(so, (int)((float)src->size->width / ratio->x), (int)((float)src->size->height / ratio->y));
	return (ratio);
}

void	so_cpy_image(t_so *so, t_sosprite_data *dest, t_sosprite_data *src)
{
	int i;
	int j;
	t_sovec2 *ratio;
	t_sovec2 *size_redem;

	if (!src || !dest)
	{
		dest = NULL;
		return ;
	}
	ratio = calculate_ratio_size(so, dest, src, &size_redem);
	i = 0;
	while (i < dest->size->height)
	{
		j = 0;
		while (j < dest->size->width)
		{
			solib_write_pixel(dest, j, i, solib_get_pixel(src, j / ratio->x, i / ratio->y));
			j++;
		}
		i++;
	}
}

void	so_put_on_grid(t_sosprite *dest, t_sosprite *src)
{
	int i;
	int j;

	if (!src || !dest)
		return ;
	i = 0;
	j = 0;
	while (i < src->transform->size->height)
	{
		j = 0;
		while (j < src->transform->size->width)
		{
			solib_write_pixel(dest->data, j + (int)src->transform->origin->x, i + (int)src->transform->origin->y, solib_get_pixel(src->data, j, i));
			j++;
		}
		i++;
	}
}

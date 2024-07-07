/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_modier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:22:28 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 04:22:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>
#include <solibft/sostring.h>
#include <solibft/sostdlib.h>

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

void	solib_write_all_pixel(t_sosprite_data *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
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

t_sovec2	*calculate_ratio_size(t_so *so, t_sosprite_data *dest,
				t_sosprite_data *src, t_sovec2 **out)
{
	t_sovec2	*ratio;

	ratio = so->vec2(so,
			(float)dest->size->width / (float)src->size->width,
			(float)dest->size->height / (float)src->size->height);
	*out = so->vec2(so, (int)((float)src->size->width / ratio->x),
			(int)((float)src->size->height / ratio->y));
	return (ratio);
}

void	cpy_sprite(t_so *so, t_sosprite *dest, t_sosprite *src)
{
	if (src->origin)
		so_cpy_image(so,
			dest->origin, src->origin);
	else
		so_cpy_image(so,
			dest->origin, src->data);
	so_cpy_image(so, dest->data, src->data);
	dest->construct->args = src->construct->args;
}

int	so_get_color(char *color)
{
	int		nbr;

	if (!color)
		return ((int)0xFF000000);
	nbr = ft_atoi_base(ft_strlower(color), "0123456789abcdef");
	return (nbr);
}

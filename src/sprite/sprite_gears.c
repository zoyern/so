/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_gears.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:32:31 by marvin            #+#    #+#             */
/*   Updated: 2024/07/08 21:32:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>
#include <solibft/sostring.h>
#include <solibft/sostdlib.h>

void	solib_sprite_adress(t_sosprite_data *data)
{
	data->adress = mlx_get_data_addr(data->ptr, &(data->bpp),
			&(data->line_len), &(data->endian));
}

void	so_first_background(t_so *so, t_sosize *size)
{
	so->area = so->new->sprite(so, so->construct(
				so, "so_background", "212121", TRUE), so->transform(
				so, so->vec2(so, 0, 0), so->size(
					so, size->width, size->height)));
}

void	sprite_cpy_img_collider(t_so *so, t_sosprite *dest, t_sosprite *sprite)
{
	if (!dest || !sprite)
		return ;
	cpy_sprite(so, dest, sprite);
	if (sprite->collider)
		collider_list_add(so, dest, sprite->construct->enabled,
			sprite->collider->callback);
	else
		dest->collider = NULL;
}

int	so_get_color(char *color)
{
	int		nbr;

	if (!color)
		return ((int)0xFF000000);
	nbr = ft_atoi_base(ft_strlower(color), "0123456789abcdef");
	return (nbr);
}

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
			so_sprite_free(so, so->grid->area[i][j]);
			j++;
		}
		so->free(so, so->grid->area[i]);
		i++;
	}
	so->free(so, so->grid->area);
	so->free(so, so->grid);
}

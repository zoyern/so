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

void solib_sprite_adress(t_sosprite_data *data)
{
	data->adress = mlx_get_data_addr(data->ptr, &(data->bpp),
									 &(data->line_len), &(data->endian));
}

t_sosprite_data	*so_get_image_data(t_so *so, char *args)
{
	t_sosprite_data	*data;
	int				width;
	int				height;

	if (!args)
		return (NULL);
	data = (t_sosprite_data *)so->malloc(so, sizeof(t_sosprite_data));
	data->ptr = mlx_xpm_file_to_image(so->mlx, args, &width, &height);
	if (!data->ptr)
		return (so->free(so, data), NULL);
	solib_sprite_adress(data);
	data->size = so->size(so, width, height);
	data->args = args;
	soimgmemory_add(so->solib, data->ptr);
	return (data);
}

t_sosprite_data	*so_get_sprite_data(t_so *so, char *args, t_sosize *size)
{
	t_sosprite_data	*data;

	data = (t_sosprite_data *)so->malloc(so, sizeof(t_sosprite_data));
	data->ptr = mlx_new_image(so->mlx, size->width, size->height);
	if (!data->ptr)
		return (so->free(so, data), NULL);
	solib_sprite_adress(data);
	data->size = size;
	data->args = args;
	soimgmemory_add(so->solib, data->ptr);
	solib_fill_sprite_color(data, args);
	return (data);
}

//permet de prendre une image et la copy dans une nouvelle image sized a la taille de size args est une couleur si la copy echou exemple pas d'image ou NULL pour resté transparent
t_sosprite_data	*so_cpy_image_sized(t_so *so, t_sosprite_data *img, char *args, t_sosize *size)
{
	t_sosprite_data	*data;

	data = so_get_sprite_data(so, args, size);
	if (!img)
		return (data);
	//copy la nouvelle image
	so_cpy_image(so, data, img);
	return (data);
}

t_sosprite	*so_sprite(t_so *so,t_soconstruct *construct, t_sotransform *transform)
{
	t_sosprite	*sprite;

	sprite = (t_sosprite *)so->malloc(so, sizeof(t_sosprite));
	sprite->construct = construct;
	sprite->transform = transform;
	//printf("%0.2f - %02f\n", sprite->transform->origin->x, sprite->transform->origin->y);
	sprite->origin = so_get_image_data(so, construct->args);
	sprite->is_image = TRUE;
	if (!sprite->origin)
	{
		sprite->origin = so_get_sprite_data(so, construct->args, transform->size);
		if (!sprite->origin)
			so->close(so, EXIT_FAILURE);
		sprite->is_image = FALSE;
	}
	sprite->data = so_cpy_image_sized(so, sprite->origin, construct->args ,transform->size);
	return (sprite);
}

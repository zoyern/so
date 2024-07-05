/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:22:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:22:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <so/all.h>

t_sosprite		*so_sprite(t_so *so, t_soconstruct *construct,	
					t_sotransform *transform);
void			solib_fill_sprite_color(t_sosprite_data *data, char *color);
void			so_grid(t_so *so, int width, int height);
void			so_show_grid(t_so *so);
t_sosprite_data	*so_cpy_image_sized(t_so *so, t_sosprite_data *img,
					char *args, t_sosize *size);
void			so_cpy_image(t_so *so, t_sosprite_data *dest,
					t_sosprite_data *src);
void			so_grid_add_background(t_so *so, char c,
					t_sosprite *sprite, char **map);
void			so_put_on_grid(t_sosprite *dest, t_sosprite *src);
void			cpy_sprite(t_so *so, t_sosprite *dest, t_sosprite *src);
int				solib_convert_color(char *color);
void			solib_write_pixel(t_sosprite_data *data, int x, int y, int color);
unsigned int	solib_get_pixel(t_sosprite_data *data, int x, int y);
t_sovec2		*calculate_ratio_size(t_so *so, t_sosprite_data *dest,
				t_sosprite_data *src, t_sovec2 **out);

#endif

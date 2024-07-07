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

#ifndef GEARS_H
# define GEARS_H

# include <so/all.h>

void			*so_malloc(t_so *so, size_t size);
int				so_free(t_so *so, void *ptr);
int				so_close(t_so *so, int state);
int				so_close_update(t_so *so, int state);
t_sofuncs		*sonew_sofuncs(t_solib *solib, int (*start)(),
					int (*update)(), int (*quit)());
t_sosize		*so_size(t_so *so, int width, int height);
t_sovec2		*so_vec2(t_so *so, float x, float y);
t_sotransform	*so_transform(t_so *so, t_sovec2 *vector2, t_sosize *size);
t_soconstruct	*so_construct(t_so *so, char *name, char *args, int enabled);

#endif

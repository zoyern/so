/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/06/04 16:53:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

int	so_quit(t_so *so)
{
	if (so->funcs->soquit)
		so->funcs->soquit(so, so->data);
	return (0);
}

int	so_update(t_so *so)
{
	if (so->loop)
	{
		if (so->funcs->soupdate)
			so->funcs->soupdate(so, so->data);
		if (so->loop)
			so_render(so);
	}
	return (0);
}

int	so_start(t_solib *solib, void *data, t_sosize *size, t_sofuncs *funcs)
{
	if (!solib->so)
		return (1);
	solib->so->funcs = funcs;
	solib->so->data = data;
	solib->so->canva = size;
	if (!solib->so->name)
		solib->so->name = "so";
	solib->so->mlx = mlx_init();
	if (!solib->so->mlx)
		return (1);
	if (!solib->so || !solib->so->canva || !solib->so->mlx)
		return (solib->so->close(solib->so, EXIT_FAILURE));
	if (so_init_windows(solib->so))
		return (solib->so->close(solib->so, EXIT_FAILURE));
	so_hooks(solib->so);
	sonew_collider(solib->so);
	solib->so->area = solib->so->new->sprite(solib->so,
			solib->so->construct(solib->so,
				"so_background", "212121", TRUE),
			solib->so->transform(solib->so,
				solib->so->vec2(solib->so, 0, 0),
				solib->so->size(solib->so, size->width, size->height)));
	if (funcs->sostart)
		funcs->sostart(solib->so, data);
	solib->so->loop = 1;
	mlx_loop_hook(solib->so->mlx, so_update, solib->so);
	mlx_loop(solib->so->mlx);
	so_quit(solib->so);
	return (so_close(solib->so, 0));
}

void	so_init(t_so *so)
{
	so->canva = NULL;
	so->start = so_start;
	so->close = so_close_update;
	so->sofuncs = sonew_sofuncs;
	so->size = so_size;
	so->vec2 = so_vec2;
	so->transform = so_transform;
	so->construct = so_construct;
	so->new = (t_sonew *)so->malloc(so, sizeof(t_sonew));
	so->new->sprite = so_sprite;
	so->new->grid = so_grid;
	so->background = so_set_background;
}

t_solib	*so(t_solib *solib, char *name)
{
	t_so	*so;

	if (!solib)
		solib = sonew_types(0, NULL, NULL);
	if (!solib)
		exit(EXIT_FAILURE);
	if (!solib->libft)
		solib = sonew_libft(solib);
	if (!solib->libft)
		solib->close(solib, EXIT_FAILURE);
	so = (t_so *)solib->malloc(solib, sizeof(t_so));
	if (!so)
		solib->close(solib, EXIT_FAILURE);
	so->print = solib->print;
	so->grid = NULL;
	if (soimgnew_memory(so))
		return (NULL);
	so->malloc = so_malloc;
	so->free = so_free;
	so->solib = solib;
	so->libft = solib->libft;
	so_init(so);
	so->inputs = so_new_keys(solib);
	so->name = name;
	solib->so = so;
	return (solib);
}

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

int		so_quit(t_so *so)
{
	so->print("%C42bf79(------%C30c734(QUIT)------)\n");
	if (so->funcs->soquit)
		so->funcs->soquit(so, so->data);
	return (0);
}

int		so_update(t_so *so)
{
	if (so->loop)
	{
		//so->print("%C42bf79(------%C30c734(UPDATE)------)\n");
		if (so->funcs->soupdate)
			so->funcs->soupdate(so, so->data);
		if(so->loop)
			so_render(so);
	}
	return (0);
}

int	so_start(t_solib *solib, void *data, t_sosize *size, t_sofuncs *funcs)
{
	if (!solib->so)
		return (1);
	solib->print("%C42bf79(------%C30c734(START)------)\n");
	solib->so->funcs = funcs;
	solib->so->data = data;
	solib->so->name = "solong";
	solib->so->cadre = size;
	solib->so->mlx = mlx_init();
	if (!solib->so->mlx)
		return (1);
	solib->print("%d -- %d -- %d\n", solib->so, solib->so->cadre->width, solib->so->cadre->height);
	if (!solib->so || !solib->so->cadre || !solib->so->mlx)
		return (solib->so->close(solib->so, EXIT_FAILURE));
	if (so_init_windows(solib->so))
		return (solib->so->close(solib->so, EXIT_FAILURE));
	if (funcs->sostart)
		funcs->sostart(solib->so, data);
	so_hooks(solib->so);
	solib->so->loop = 1;
	mlx_loop_hook(solib->so->mlx, so_update, solib->so);
	mlx_loop(solib->so->mlx);
	so_quit(solib->so);
	return (so_close(solib->so, 0));
}

void	so_init(t_so *so)
{
	so->start =  so_start;
	so->close =  so_close_update;
	so->sofuncs =  sonew_sofuncs;
	so->size = so_size;
	so->vec2 = so_vec2;
	so->transform = so_transform;
	so->construct = so_construct;
	so->sprite = so_sprite;
}

t_solib	*so(t_solib *solib)
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
	so->print =  solib->print;
	if (soimgnew_memory(so))
		return (NULL);
	so_init(so);
	so->solib = solib;
	so->cadre = NULL;
	so->libft =  solib->libft;
	so->malloc =  so_malloc;
	so->free =  so_free;
	so->inputs = so_new_keys(solib);
	solib->so = so;
	return (solib);
}

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
	return (so_close(so, EXIT_SUCCESS));
}

int		so_update(t_so *so)
{
	if (so->loop)
	{
		so->print("%C42bf79(------%C30c734(UPDATE)------)\n");
		if (so->funcs->soupdate)
			so->funcs->soupdate(so, so->data);
	}
	return (0);
}

int		so_start(t_solib *solib, void *data, t_sofuncs *funcs)
{
	solib->print("%C42bf79(------%C30c734(QUIT)------)\n");
	solib->so->funcs = funcs;
	solib->so->data = data;
	solib->so->mlx = mlx_init();
	if (!solib->so->mlx)
		return (1);
	if (funcs->sostart)
		funcs->sostart(solib->so, data);
	if (so_init_windows(solib->so))
		return (1);
	so_hooks(solib->so);
	solib->so->loop = 1;
	mlx_loop_hook(solib->so->mlx, so_update, solib->so);
	mlx_loop(solib->so->mlx);
	so_quit(solib->so);
	return (0);
}

void	so_init(t_so *so)
{
	so->width = 0;
	so->height = 0;
	so->start =  so_start;
	so->close =  so_close_update;
	so->sofuncs =  sonew_sofuncs;
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
	so_init(so);
	so->libft =  solib->libft;
	so->print =  solib->print;
	so->malloc =  solib->malloc;
	so->free =  solib->free;
	so->inputs = so_new_keys(solib);
	solib->so = so;
	solib->so->solib = solib;
	return (solib);
}

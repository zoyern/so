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

int so_close(t_so *so, int state)
{
	if (so)
	{
		if (so->display)
			mlx_destroy_window(so->mlx, so->display);
		if (so->mlx)
		{
			mlx_destroy_display(so->mlx);
			free(so->mlx);
		}
		free(so);
	}
	if (state)
		exit(EXIT_FAILURE);
	return(state);
}

int		so_start(t_solib *solib, void *data, t_sofuncs *funcs)
{
	solib->print("%C42bf79(------%C30c734(STARTING)------)\n");
	if (funcs->sostart)
		funcs->sostart(solib->so, (void *)data);
	if (funcs->soupdate)
		funcs->soupdate(solib->so, (void *)data);
	if (funcs->soquit)
		funcs->soquit(solib->so, (void *)data);
	return (0);
}

t_sofuncs	*sonew_sofuncs(t_solib *solib, int (*start)(t_so *so, void *data), int (*update)(t_so *so, void *data), int (*quit)(t_so *so, void *data))
{
	t_sofuncs	*funcs;

	funcs = solib->malloc(solib, sizeof(t_sofuncs));
	funcs->sostart = start;
	funcs->soupdate = update;
	funcs->soquit = quit;
	return (funcs);
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
	so->start =  so_start;
	so->close =  so_close;
	so->init =  sonew_sofuncs;
	solib->so = so;
	return (solib);
}

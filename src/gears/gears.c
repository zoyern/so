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

int so_close(t_so *so, int state)
{
	if (so)
	{
		if (so->window)
			mlx_destroy_window(so->mlx, so->window);
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

t_sofuncs	*sonew_sofuncs(t_solib *solib, int (*start)(), int (*update)(), int (*quit)())
{
	t_sofuncs	*funcs;

	funcs = solib->malloc(solib, sizeof(t_sofuncs));
	funcs->sostart = start;
	funcs->soupdate = update;
	funcs->soquit = quit;
	return (funcs);
}
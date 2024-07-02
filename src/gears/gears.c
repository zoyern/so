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

int so_close_update(t_so *so, int state)
{
	if (so->mlx)
		mlx_loop_end(so->mlx);
	so->loop = 0;
	if (state)
		so_close(so, state);
	return (state);
}


int so_close(t_so *so, int state)
{
	if (so)
	{
		so->imgmemory->close(so->solib);
		if (so->window && so->mlx)
			mlx_destroy_window(so->mlx, so->window);
		if (so->mlx)
		{
			mlx_destroy_display(so->mlx);
			free(so->mlx);
		}
		so->free(so, so);
	}
	if (state)
		exit(state);
	return (state);
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

void	*so_malloc(t_so *so, size_t size)
{
	return (so->solib->malloc(so->solib, size));
}

int	so_free(t_so *so, void *ptr)
{
	return (so->solib->free(so->solib, ptr));
}
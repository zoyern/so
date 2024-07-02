/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

void	so_free_grid(t_so *so)
{
	if (!so->grid)
		return ;
	int	i = 0;
	int j = 0;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			so->free(so, so->grid->area[i][j]);
			j++;
		}
		so->free(so, so->grid->area[i]);
		i++;
	}
	so->free(so, so->grid);
}

void	so_grid(t_so *so, int width, int height)
{
	so->print("grided :) %d -- %d\n", width, height);
	if (so->grid)
		so_free_grid(so);
	so->grid = so->malloc(so, sizeof(t_sogrid));
	so->grid->width = width;
	so->grid->height = height;
	so->grid->area = so->malloc(so, sizeof(t_sosprite **) * (height));
	int i = 0;
	int j = 0;
	while (i < height)
	{
		j = 0;
		so->grid->area[i] = so->malloc(so, sizeof(t_sosprite *) * (width));
		while (j < width)
		{
			so->grid->area[i][j] = NULL;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			so->print("%p,",so->grid->area[i][j]);
			j++;
		}
		so->print("\n");
		i++;
	}
}
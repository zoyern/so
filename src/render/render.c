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
#include <stdio.h>

void	so_put_grid(t_so *so)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!so->grid)
		return ;
	while (i < so->grid->height)
	{
		j = 0;
		while (j < so->grid->width)
		{
			//printf(" - so->grid->area[%d][%d]  -- %f -- %f | %d -- %d\n",i, j - 1,  grid->area[i][j - 1]->transform->origin->x, grid->area[i][j - 1]->transform->origin->y, grid->area[i][j - 1]->transform->size->width, grid->area[i][j - 1]->transform->size->height);
			so_put_on_grid(so->area, so->grid->area[i][j]);
			j++;
		}
		//so->print("\n");
		i++;
	}
}

int	so_render(t_so *so)
{
	so_put_grid(so);
	mlx_put_image_to_window(so->mlx, so->window, so->area->data->ptr, 0, 0);
	return (0);
}
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

void	so_windows_init_size(t_so *so, int *width, int *height)
{
	int				_width;
	int				_height;

	_width = 0;
	_height = 0;
	if (*width >= 1 && *height >= 1)
		return ;
	mlx_get_screen_size(so->mlx, &_width, &_height);
	if (*width < 1)
		*width = _width;
	if (*height < 1)
		*height = _height;
}

int	so_init_windows(t_so *so)
{
	if (!so || !so->cadre || !so->mlx || !so->name)
		return (1);
	so_windows_init_size(so, &so->cadre->width, &so->cadre->height);
	so->window = mlx_new_window(so->mlx, so->cadre->width, so->cadre->height, so->name);
	if (!so->window)
		return (1);
	return (0);
}
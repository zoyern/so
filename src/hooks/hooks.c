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

void	so_hooks(t_so *so)
{
	mlx_hook(so->window,
		17, 1L << 0, so->close, so);
	mlx_hook(so->window,
		KeyPress, KeyPressMask, &solib_key_press, so);
	mlx_hook(so->window,
		KeyRelease, KeyReleaseMask, &solib_key_release, so);
}

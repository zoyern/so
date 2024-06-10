/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:22:09 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:22:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>

t_sokeys	*so_new_keys(t_solib *solib)
{
	t_sokeys	*inputs;
	int			i;

	inputs = solib->malloc(solib, sizeof(t_sokeys));
	i = 0;
	while (i < 256)
	{
		inputs->keys[i] = FALSE;
		i++;
	}
	inputs->escape = FALSE;
	inputs->mouse = solib->malloc(solib, sizeof(t_sovec2));
	inputs->mouse->x = 0;
	inputs->mouse->y = 0;
	return (inputs);
}

int	solib_key_press(int keycode, t_so *so)
{
	if (keycode < 256)
		so->inputs->keys[keycode] = TRUE;
	if (keycode == 65307)
		so->inputs->escape = TRUE;
	return (0);
}

int	solib_key_release(int keycode, t_so *so)
{
	if (keycode < 256)
		so->inputs->keys[keycode] = FALSE;
	if (keycode == 65307)
		so->inputs->escape = FALSE;
	return (0);
}

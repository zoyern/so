/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 14:35:26 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exemple.h"
#include "so/sprite.h"

int	start(t_so *so, t_data *data)
{
	t_sosprite	*wall;
	t_sosprite	*ground;
	t_sosprite	*enemy;

	so->new->grid(so, data->map->width, data->map->height);
	wall = so->new->sprite(so,
			so->construct(so, "wall", "assets/images/test.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 47)));
	ground = so->new->sprite(so,
			so->construct(so, "ground", "assets/images/test2.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 47)));
	enemy = so->new->sprite(so,
			so->construct(so, "enemy", "assets/images/ennemy.xpm", TRUE),
			so->transform(so,
				so->vec2(so, data->map->player.width * so->grid->raw , data->map->player.height * so->grid->collum),
				so->size(so, so->grid->raw, so->grid->collum)));
	so->grid->background(so, '1', wall, data->map->collider);
	so->grid->background(so, 'X', ground, data->map->collider);
	sprite_list_add(so, so->grid->list, enemy);
	return (0);
}

int	update(t_so *so, t_data *data)
{
	data->value = 2;
	//so->print("Update ----value : %d-----\n", data->value);
	if (so->inputs->escape)
		return (so->close(so, EXIT_SUCCESS));
	return (0);
}

int	quit(t_so *so, t_data *data)
{
	data->value = 3;
	so->print("Quit ----value : %d-----\n", data->value);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_solib	*solib;
	t_data	*data;
	t_map	*map;

	solib = so(sonew_types(argc, argv, envp));
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	map = get_map(solib, "assets/maps/tmp.ber");
	if (!map)
		return (solib->print("ERROR MAP\n"), solib->close(solib, EXIT_FAILURE));
	data = solib->malloc(solib, sizeof(t_data));
	data->map = map;
	if (solib->so->start(solib, data, solib->so->size(solib->so, 800, 500),
			solib->so->sofuncs(solib, start, update, quit)))
		return (solib->print("EXIT GAME ERROR\n"),
			solib->so->close(solib->so, EXIT_FAILURE));
	return (solib->close(solib, EXIT_SUCCESS));
}

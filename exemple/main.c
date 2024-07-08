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
#include "so/colliders.h"
#include <stdio.h>

int	wall_collider_callback(t_so *so, t_data *data, t_socollider *src, t_socollider *object)
{
	(void)so;
	(void)src;
	(void)object;
	if (!so->libft->strncmp(object->sprite->construct->name, "enemy", 5))
	{
		data->map->collectible--;
		   so->print("gg tu as recuperer un coin !! reste : %d\n", data->map->collectible);
		   src->enabled = FALSE;
		   src->sprite->construct->enabled = FALSE;
	}
	return (0);
}


int	player_collider_callback(t_so *so, t_data *data, t_socollider *src, t_socollider *object)
{
	(void)so;
	(void)src;
	(void)object;
	(void)data;
	/*if (!so->libft->strncmp(object->sprite->construct->name, "wall", 4))
		so->print("playercolider_callback - collider : %s tappé par : %s\n", src->sprite->construct->name, object->sprite->construct->name);*/
	return (0);
}

int	start(t_so *so, t_data *data)
{
	t_sosprite	*wall;
	t_sosprite	*ground;
	t_sosprite	*enemy;
	t_sosprite	*ring;

	so->new->grid(so, data->map->width, data->map->height);
	wall = so->new->sprite(so,
			so->construct(so, "wall", "assets/images/test.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 50)));
	collider_list_add(so, wall, FALSE, NULL);
	ground = so->new->sprite(so,
			so->construct(so, "ground", "assets/images/test2.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 47)));
	enemy = so->new->sprite(so,
			so->construct(so, "enemy", "assets/images/ennemy.xpm", TRUE),
			so->transform(so,
				so->vec2(so, data->map->player.width - so->grid->raw + 200 , data->map->player.height * so->grid->collum - 200),
				so->size(so, 15, 15)));
	collider_list_add(so, enemy, TRUE, player_collider_callback);
	ring = so->new->sprite(so,
			so->construct(so, "ring", "assets/images/ring.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 20, 20)));
	collider_list_add(so, ring, FALSE, wall_collider_callback);
	so->grid->background(so, '1', wall, data->map->collider);
	so->grid->background(so, 'X', ground, data->map->collider);
	so->grid->add(so, enemy);
	so->grid->adds(so, 'C', ring, data->map->origin);
	collider_list_show(so);
	return (0);
}

#include <stdio.h>

int	update(t_so *so, t_data *data)
{
	data->value = 2;
	t_sosprite	*enemy2 = so->grid->get(so, "enemy", so->grid->list);
	t_sovec2	inputs;

	inputs.x = 0;
	inputs.y = 0;
	if (so->inputs->escape)
		return (so->close(so, EXIT_SUCCESS));
	//so->print("hhhhhhhhhhheeeeeeeeeeyyyyyyyyyyyyyyyyy get sprite baby - %s\nargs : %s\n", enemy2->construct->name, enemy2->construct->args);
	if (so->inputs->keys['z'])
		inputs.y -= 1;
	if (so->inputs->keys['q'])
		inputs.x -= 1;
	if (so->inputs->keys['s'])
		inputs.y += 1;
	if (so->inputs->keys['d'])
		inputs.x += 1;
	//printf("[%f][%f]\n", inputs.x, inputs.y);
	so_move_and_check(so, inputs, enemy2);
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

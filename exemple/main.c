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

#define CONSTANTE 0.004

int	player_collider_callback(t_so *so, t_data *data, t_socollider *src,
		t_socollider *object)
{
	(void)src;
	if (!so->libft->strncmp(object->sprite->construct->name, "ring", 4))
	{
		object->enabled = FALSE;
		object->sprite->construct->enabled = FALSE;
		data->collectible--;
		so->print("gg tu as recuperer un coin !! reste : %d\n",
			data->collectible);
		if (data->collectible <= 0)
		{
			so->grid->get(so, "dore", so->grid->list)
				->construct->enabled = TRUE;
			so->grid->get(so, "dore", so->grid->list)
				->collider->enabled = TRUE;
		}
	}
	if (!so->libft->strncmp(object->sprite->construct->name, "dore", 5))
	{
		so->print("%CECEC53(GG WP TA WIN !!)\n");
		so->close(so, EXIT_SUCCESS);
	}
	return (0);
}

void	data_init_sprite(t_so *so, t_data *data)
{
	data->wall = so->new->sprite(so,
			so->construct(so, "wall", "assets/images/test.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 50)));
	data->ground = so->new->sprite(so,
			so->construct(so, "ground", "assets/images/test2.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 50, 47)));
	data->enemy = so->new->sprite(so,
			so->construct(so, "enemy", "assets/images/ennemy.xpm", TRUE),
			so->transform(so,
				so->vec2(so, data->player.width * so->grid->raw
					+(so->grid->raw / 2),
					data->player.height * so->grid->collum
					+ (so->grid->collum / 2)),
				so->size(so, 15, 15)));
	data->ring = so->new->sprite(so,
			so->construct(so, "ring", "assets/images/ring.xpm", TRUE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, 20, 20)));
	data->dore = so->new->sprite(so,
			so->construct(so, "dore", "assets/images/lotr_map.xpm", FALSE),
			so->transform(so, so->vec2(so, 0, 0),
				so->size(so, so->grid->raw, so->grid->collum)));
}

int	start(t_so *so, t_data *data)
{
	data->movement = 0;
	so->new->grid(so, data->width, data->height);
	data_init_sprite(so, data);
	so->colliders->add(so, data->enemy, TRUE, player_collider_callback);
	so->colliders->add(so, data->wall, FALSE, NULL);
	so->colliders->add(so, data->ring, FALSE, NULL);
	so->colliders->add(so, data->dore, FALSE, NULL);
	so->grid->background(so, '1', data->wall, data->collider);
	so->grid->background(so, 'X', data->ground, data->collider);
	so->grid->add(so, data->enemy);
	so->grid->adds(so, 'C', data->ring, data->origin);
	so->grid->adds(so, 'E', data->dore, data->origin);
	return (0);
}

int	update(t_so *so, t_data *data)
{
	t_sovec2	inputs;

	if (so->inputs->escape)
		return (so->close(so, EXIT_SUCCESS));
	inputs.x = 0;
	inputs.y = 0;
	if (so->inputs->keys['z'] || so->inputs->keys['w'])
		inputs.y -= 20 + (so->canva->width * CONSTANTE);
	if (so->inputs->keys['q'] || so->inputs->keys['a'])
		inputs.x -= 20 + + (so->canva->width * CONSTANTE);
	if (so->inputs->keys['s'])
		inputs.y += 20 + + (so->canva->width * CONSTANTE);
	if (so->inputs->keys['d'])
		inputs.x += 20 + (so->canva->width * CONSTANTE);
	if (so->inputs->keys['z'] || so->inputs->keys['q']
		|| so->inputs->keys['s'] || so->inputs->keys['d']
		|| so->inputs->keys['w'] | so->inputs->keys['a'])
	{
		data->movement++;
		so->print("%C1313ac(movement : )%Cfdee00(%d)\n", data->movement);
	}
	so->move(so, inputs, so->grid->get(so, "enemy", so->grid->list));
	if (so->inputs->escape)
		return (so->close(so, EXIT_SUCCESS));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_solib	*solib;
	t_data	*data;

	solib = so(sonew_types(argc, argv, envp), "solong");
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	if (solib->env->argc != 1)
		return (solib->print("ERROR ARG\n"), solib->close(solib, 1));
	data = get_map(solib, solib->env->argv[0]);
	if (!data)
		return (solib->print("ERROR MAP\n"), solib->close(solib, EXIT_FAILURE));
	if (solib->so->start(solib, data, solib->so->size(solib->so, 1280, 720),
			solib->so->sofuncs(solib, start, update, NULL)))
		return (solib->print("EXIT GAME ERROR\n"),
			solib->so->close(solib->so, EXIT_FAILURE));
	return (solib->close(solib, EXIT_SUCCESS));
}

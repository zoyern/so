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

#define WALL "000000"
#define GROUND "00FF00"
#define PLAYER "0000FF"
#define COLLECTIBLE "FFFF00"
#define PLAYER_EXIT "FF0000"

char	***map_to_sprite(t_so *so, t_map *map)
{
	char	***out;
	int		i;
	int		j;

	i = 0;
	out	= so->malloc(so, sizeof(char *) * (map->height));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			out[i]	= so->malloc(so, sizeof(char) * (map->width));
			if (map->collider[i][j] == '1')
				out[i][j] = WALL;
			else if (map->collider[i][j] == 'X')
				out[i][j] = GROUND;
			j++;
		}
		i++;
	}
	return (out);
}

void	so_show_map(t_so *so, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map)
		return ;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			so->print("%c,",map->collider[i][j]);
			j++;
		}
		so->print("\n");
		i++;
	}
}

int	start(t_so *so, t_data *data)
{
	data->value = 1;
	so->print("Start ----value : %d-----\n", data->value);
	so->new->grid(so, data->map->width, data->map->height);
	t_sosprite *wall = so->new->sprite(so,
	so->construct(so,
		"canva1", "assets/images/lotr_map.xpm", TRUE),
	so->transform(so,
		so->vec2(so, 0, 0),
		so->size(so, 50, 47)));
	t_sosprite *ground = so->new->sprite(so,
	so->construct(so,
		"canva1", "assets/images/ring.xpm", TRUE),
	so->transform(so,
		so->vec2(so, 0, 0),
		so->size(so, 1920, 1080)));

	t_sosprite *enemy = so->new->sprite(so,
	so->construct(so,
		"canva1", "assets/images/ring.xpm", TRUE),
	so->transform(so,
		so->vec2(so, so->grid->area[data->map->player_y][data->map->player_x]->transform->origin->x,
		so->grid->area[data->map->player_y][data->map->player_x]->transform->origin->y),
		so->size(so, 50, 50)));

	so->grid->background(so, '1', wall, data->map->collider);
	so->grid->background(so, 'X', ground, data->map->collider);
	so->grid->show(so);
	so->print("\n");
	(void)enemy;
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
		return (solib->print("EXIT GAME ERROR\n"), solib->so->close(solib->so, EXIT_FAILURE));
	return (solib->close(solib, EXIT_SUCCESS));
	
	/*solib->print("╔══❖═══════❖══╗\n");
	solib->print("║      SO     ║\n");
	solib->print("║             ║\n");
	solib->print("║ loading :✅ ║\n");
	solib->print("╚══❖═══════❖══╝\n");*/
}

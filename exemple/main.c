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

int	start(t_so *so, t_data *data)
{
	data->value = 1;
	so->print("Start ----value : %d-----\n", data->value);

	char cwd[4096];
	//t_socam *cam = so->new->camera(so,
	t_sosprite *sprite = so->sprite(so,
	so->construct(so,
		"canva1", "assets/images/lotr_map.xpm", TRUE),
	so->transform(so,
		so->vec2(so, 0, 0),
		so->size(so, 1920, 1080)));
	getcwd(cwd, sizeof(cwd));
	so->print("getcwd : %s\n", cwd);
	so->print("image trouvé ? : %p\n", sprite->origin->ptr);
	so->print("image2 trouvé ? : %p\n", sprite->data->ptr);
	so->area = sprite;

// j'ai deja mon image de display

	/*char	**map	= "" "coucou"
	t_sosprite sliced_image[data->map->height][data->map->width] = [ 
	["", ]
	[]
	];
	so->area(so, )
	
	*/
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

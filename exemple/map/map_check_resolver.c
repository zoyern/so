/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soexec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:00:43 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 22:00:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exemple.h"

#define WALL "000000"
#define GROUND "00FF00"
#define PLAYER "0000FF"
#define COLLECTIBLE "FFFF00"
#define PLAYER_EXIT "FF0000"

char	**resolved_path(t_data *data, char **map, int x, int y)
{
	if (!map)
		return (NULL);
	map[x][y] = 'X';
	if ((x > 0) && ((map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x
			- 1][y] == 'E' || map[x - 1][y] == 'P')))
		resolved_path(data, map, x - 1, y);
	if ((x < data->height) && ((map[x + 1][y] == '0' || map[x + 1][y] == 'C'
		|| map[x + 1][y] == 'E' || map[x + 1][y] == 'P')))
		resolved_path(data, map, x + 1, y);
	if ((y < data->width) && ((map[x][y + 1] == '0' || map[x][y + 1] == 'C'
		|| map[x][y + 1] == 'E' || map[x][y + 1] == 'P')))
		resolved_path(data, map, x, y + 1);
	if ((y > 0) && ((map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x]
		[y - 1] == 'E' || map[x][y - 1] == 'P')))
		resolved_path(data, map, x, y - 1);
	return (map);
}

int	check_path(t_data *map)
{
	int	x;
	int	y;

	map->collider = resolved_path(map, map->collider,
			map->player.width, map->player.height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->collider[y][x] == 'C' || map->collider[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	***map_to_sprite(t_so *so, t_data *map)
{
	char	***out;
	int		i;
	int		j;

	i = 0;
	out = so->malloc(so, sizeof(char *) * (map->height));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			out[i] = so->malloc(so, sizeof(char) * (map->width));
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

int	get_size_map(char *mapfile, int *width, int *height)
{
	int		x_tmp;
	int		fd;
	char	buf;

	*height = 0;
	*width = 0;
	x_tmp = 0;
	fd = open(mapfile, O_RDONLY, 0644);
	if (fd < 0)
		return (1);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			if (check_map_condition_return(height, width, &x_tmp))
				return (close(fd), 1);
		}
		else
			x_tmp++;
	}
	return (get_size_map_res(width, height, x_tmp, fd));
}

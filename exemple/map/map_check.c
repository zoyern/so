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

int	check_border_row(char **map, int y, int max_x)
{
	int	x;

	x = 0;
	while (x < max_x)
	{
		if (map[y][x] != '1' && map[y][x] != '\0')
			return (1);
		x++;
	}
	return (0);
}

int	check_border_col(char **map, int x, int max_y)
{
	int	y;

	y = 0;
	while (y < max_y)
	{
		if (map[y][x] != '1' && map[y][x] != '\0')
			return (1);
		y++;
	}
	return (0);
}

int	is_char(char c, char c2, t_sosize *dest_size, t_sosize src_size)
{
	if (c != c2)
		return (0);
	*dest_size = src_size;
	return (1);
}

int	check_collectible_identifier(t_map *map)
{
	int			exit;
	int			player;
	t_sosize	vec2;

	vec2.height = 0;
	exit = 0;
	player = 0;
	while (vec2.height < map->height)
	{
		vec2.width = 0;
		while (vec2.width < map->width)
		{
			map->collectible += is_char(map->origin[vec2.height][vec2.width], 'C', &vec2, vec2);
			exit += is_char(map->origin[vec2.height][vec2.width], 'E', &map->exit, vec2);
			player += is_char(map->origin[vec2.height][vec2.width], 'P', &map->player, vec2);
			vec2.width ++;
		}
		vec2.height++;
	}
	if (exit != 1 || player != 1 || map->collectible < 1)
		return (1);
	return (0);
}

int	check_collectible(t_map *map)
{
	map->collectible = 0;
	map->exit.width = 0;
	map->exit.height = 0;
	map->player.width = 0;
	map->player.height = 0;
	return (check_collectible_identifier(map));
}

char	**resolved_path(t_map *data, char **map, int x, int y)
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


int	check_path(t_map *map)
{
	int	x;
	int	y;

	map->collider = resolved_path(map, map->collider, map->player.width, map->player.height);
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

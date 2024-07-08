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

#include "../exemple.h"

int	check_map_condition_return(int *y, int *x, int *x_tmp)
{
	if (*x <= 0)
		*x = *x_tmp;
	else if (*x != *x_tmp)
		return (1);
	*x_tmp = 0;
	*y += 1;
	return (0);
}

// je pense donc je suis !
//lenfer c'est les autres

int	get_size_map_res(int *width, int *height, int x_tmp, int fd)
{
	if (*width != x_tmp + 1)
		return (close(fd), 1);
	*width = x_tmp;
	*height += 1;
	close(fd);
	return (0);
}

int	check_map(t_data *map)
{
	int	check;

	if (!map || !map->origin)
		return (1);
	check = 0;
	check += check_border_row(map->origin, 0, map->width);
	check += check_border_row(map->origin, map->height - 1, map->width);
	check += check_border_col(map->origin, 0, map->height);
	check += check_border_col(map->origin, map->width - 1, map->height);
	check += map_check(map);
	check += check_path(map);
	if (check > 0)
		return (1);
	return (0);
}

t_data	*create_map(t_solib *solib, int width, int height, char *mapfile)
{
	t_data	*map;
	int		fd;
	char	buf;
	char	*str;
	int		i;

	map = solib->malloc(solib, sizeof(t_data));
	str = solib->malloc(solib, sizeof(char) * (4096 + 1));
	map->width = width;
	map->height = height;
	fd = open(mapfile, O_RDONLY, 0644);
	if (fd < 0)
		return (0);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		str[i++] = buf;
	str[i] = 0;
	map->origin = solib->libft->split(solib, str, '\n');
	map->collider = solib->libft->split(solib, str, '\n');
	solib->free(solib, str);
	close(fd);
	if (check_map(map))
		return (NULL);
	return (map);
}

t_data	*get_map(t_solib *solib, char *mapfile)
{
	int		width;
	int		height;

	if (get_size_map(mapfile, &width, &height))
		return (0);
	return (create_map(solib, width, height, mapfile));
}

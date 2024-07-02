/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:27:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 14:43:35 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEMPLE_H
# define EXEMPLE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <solibft.h>
# include <mlx.h>
# include <so.h>

typedef struct s_map	t_map;
typedef struct s_data	t_data;

typedef struct s_map
{
	int	width;
	int height;
	int	collectible;
	int	player_x;
	int player_y;
	int exit_x;
	int	exit_y;

	char	**origin;
	char	**collider;
			
}	t_map;

typedef struct s_data
{
	t_map	*map;
	int		value;
			
}	t_data;

t_map	*get_map(t_solib *solib, char *mapfile);
int		check_border_row(char **map, int y, int max_x);
int		check_border_col(char **map, int x, int max_y);
int		check_collectible(t_map *map);
char	**resolved_path(t_map *data, char **map, int x, int y);
int		check_path(t_map *map);

#endif
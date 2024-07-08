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
# include <sotypes/soprintf.h>
# include <mlx.h>
# include <so.h>

typedef struct s_data
{
	int			movement;
	int			width;
	int			height;
	int			collectible;
	t_sosize	player;
	t_sosize	exit;

	char		**origin;
	char		**collider;

	t_sosprite	*wall;
	t_sosprite	*ground;
	t_sosprite	*enemy;
	t_sosprite	*ring;
	t_sosprite	*dore;
}	t_data;

t_data	*get_map(t_solib *solib, char *mapfile);
int		check_border_row(char **map, int y, int max_x);
int		check_border_col(char **map, int x, int max_y);
int		map_check(t_data *map);
char	**resolved_path(t_data *data, char **map, int x, int y);
int		check_path(t_data *map);
int		get_size_map(char *mapfile, int *width, int *height);
int		check_map_condition_return(int *y, int *x, int *x_tmp);
int		get_size_map_res(int *width, int *height, int x_tmp, int fd);

#endif
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

int	start(t_so *so, t_data *data)
{
	so->print("Start ----value : %d-----\n", data->value);
	so->name = "solong";
	so->width = 800;
	so->height = 500;
	data->value = 1;
	return (0);
}

int	update(t_so *so, t_data *data)
{
	so->print("Update ----value : %d-----\n", data->value);
	if (so->inputs->escape)
		return (so->close(so, EXIT_SUCCESS));
	data->value = 2;
	return (0);
}

int	quit(t_so *so, t_data *data)
{
	so->print("Quit ----value : %d-----\n", data->value);
	data->value = 3;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_solib	*solib;
	t_data	*data;

	solib = so(sonew_types(argc, argv, envp));
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	solib->print("╔══❖═══════❖══╗\n");
	solib->print("║      SO     ║\n");
	solib->print("║             ║\n");
	solib->print("║ loading :✅ ║\n");
	solib->print("╚══❖═══════❖══╝\n");
	data = solib->malloc(solib, sizeof(t_data));
	data->value = 0;
	if (solib->so->start(solib, data, solib->so->sofuncs(solib,
		 start, update, quit)))
		return (solib->close(solib, EXIT_FAILURE));
	return (solib->close(solib, EXIT_SUCCESS));
}

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

int	main(int argc, char **argv, char **envp)
{
	t_solib		*solib;

	solib = sonew_libft(sonew_types(argc, argv, envp));
	solib = so(solib);
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	if (!solib->so)
		return (solib->close(solib, EXIT_FAILURE));
	solib->print("╔══❖═══════❖══╗\n");
	solib->print("║      SO     ║\n");
	solib->print("║             ║\n");
	solib->print("║ loading :✅ ║\n");
	solib->print("╚══❖═══════❖══╝\n");
	if (solib->so->start(solib))
		return (solib->close(solib, EXIT_FAILURE));
	return (solib->close(solib, EXIT_SUCCESS));
}

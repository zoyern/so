/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 13:36:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

t_solib	*sonew_libft(t_solib *solib)
{
	t_solibft	*solibft;

	if (!solib)
		solib = sonew_types(0, NULL, NULL);
	if (!solib)
		exit(EXIT_FAILURE);
	solibft = (t_solibft *)solib->malloc(solib, sizeof(t_solibft));
	if (!solibft)
		solib->close(solib, EXIT_FAILURE);
	sonew_ctype(solibft);
	sonew_stdio(solibft);
	sonew_stdlib(solibft);
	sonew_sostring(solibft);
	solib->libft = solibft;
	return (solib);
}

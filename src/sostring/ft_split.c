/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:14:13 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:04:58 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solibft/all.h>

int	get_count_word(char const *str, char c)
{
	int	k;

	k = 0;
	while (*str)
	{
		if (str[0] != c && (str[1] == c || !str[1]))
			k++;
		str++;
	}
	return (k);
}

int	get_word_len(char const *str, char c)
{
	int	k;

	k = 0;
	while (str[k] && str[k] != c)
		k++;
	return (k);
}

int	free_all(char **array)
{
	int	k;

	k = 0;
	while (array[k])
		free(array[k++]);
	free(array);
	return (1);
}

char	**ft_split(t_solib *solib, char const *s, char c)
{
	char	**out;
	int		out_len;
	int		k;
	int		word_len;

	out_len = get_count_word(s, c);
	out = solib->malloc(solib, sizeof(char *) * (out_len + 1));
	if (!out)
		return (0);
	k = 0;
	while (k < out_len)
	{
		while (*s == c)
			s++;
		word_len = get_word_len(s, c);
		out[k] = ft_substr(solib, s, 0, word_len);
		if (!out[k] && free_all(out))
			return (0);
		s += word_len;
		k++;
	}
	out[out_len] = 0;
	return (out);
}

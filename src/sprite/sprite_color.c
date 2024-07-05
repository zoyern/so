/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:22:27 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 03:22:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>
#include <sotypes/soprintf.h>

unsigned long	so_sprite_ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*so_sprite_ft_strdup(const char *s)
{
	unsigned long	len;
	char			*t;

	if (!s)
		return (NULL);
	len = so_sprite_ft_strlen(s);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	while (*s)
		*t++ = *s++;
	*t = '\0';
	return (t -= len);
}

char	*so_sprite_lower_case(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	so_sprite_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (1);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	so_sprite_find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	so_sprite_index_num(char c, char *base)
{
	int	c_index;

	c_index = 0;
	while (base[c_index] && base[c_index] != c)
		c_index++;
	return (c_index);
}

int	so_sprite_atoi_base(char *str, char *base)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	if (so_sprite_check_base(base))
		return (num * sign);
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (so_sprite_find_in_base(str[i], base))
	{
		num = (num * so_sprite_ft_strlen(base) + so_sprite_index_num(str[i], base));
		i++;
	}
	return (num * sign);
}

int	solib_convert_color(char *color)
{
	char	*str;
	int		nbr;

	soprintf("hey %s !!!\n", color);
	if (!color)
		return ((int)0xFF000000);
	str = so_sprite_lower_case(so_sprite_ft_strdup(color));
	nbr = so_sprite_atoi_base(str, "0123456789abcdef");
	soprintf("hey !!!\n");
	free(str);
	return (nbr);
}
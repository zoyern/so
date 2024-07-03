/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:08:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/05 18:08:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so/all.h>
#include <sotypes/soprintf.h>

void solib_write_pixel(t_sosprite_data *data, int x, int y, int color)
{
	char *dst;

	dst = NULL;
	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < data->size->width && y < data->size->height)
	{
		dst = (data->adress + ((x + (y) * (data->size->width)) * (data->bpp / 8)));
	}
	*(unsigned int *)dst = color;
}

unsigned int solib_get_pixel(t_sosprite_data *data, int x, int y)
{
	return (*(unsigned int *)(data->adress + ((x + (y) * (data->size->width)) * (data->bpp / 8))));
}

unsigned long ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	unsigned long len;
	char *t;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	while (*s)
		*t++ = *s++;
	*t = '\0';
	return (t -= len);
}

char *lower_case(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (src[i] >= 'A' && src[i] <= 'Z')
			dest[i] += 32;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int get_base_length(char *base)
{
	int base_length;
	int j;

	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == '-' || base[base_length] == '+')
			return (0);
		j = base_length + 1;
		while (base[j])
		{
			if (base[base_length] == base[j])
				return (0);
			++j;
		}
		++base_length;
	}
	if (base_length < 2)
		return (0);
	return (base_length);
}

int check_errors(char *str, char *base)
{
	int i;
	int j;
	int start;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
								  str[start] == '\r' || str[start] == '\n' || str[start] == '\v' ||
								  str[start] == '\f'))
		start++;
	i = start;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j] ||
						   (str[i] == '-' || str[i] == '+')))
			++j;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int get_nb(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int solib_convert_color(char *color)
{
	int s;
	int i;
	int res;
	int negative;
	int base_length;

	char *base = "0123456789abcdef";
	char *str = ft_strdup(color);

	if (!color)
		return (-1);
	lower_case(str, color);

	if (!(base_length = get_base_length(base)) || !check_errors(str, base))
		return (free(str), -1);
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r' || str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
						(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}
	free(str);
	return (res * negative);
}

void solib_fill_sprite_color(t_sosprite_data *data, char *color)
{
	int i;
	int j;
	int c;
	i = 0;
	c = solib_convert_color(color);
	if (c < 0)
		c = (int)0xFF000000;
	while (i < data->size->height)
	{
		j = 0;
		while (j < data->size->width)
		{
			solib_write_pixel(data, j, i, c);
			j++;
		}
		i++;
	}
}

t_sovec2 *calculate_ratio_size(t_so *so, t_sosprite_data *dest, t_sosprite_data *src, t_sovec2 **out)
{
	t_sovec2 *ratio;
	ratio = so->vec2(so,
		(float)dest->size->width / (float)src->size->width,
		(float)dest->size->height / (float)src->size->height);
	*out = so->vec2(so, (int)((float)src->size->width / ratio->x), (int)((float)src->size->height / ratio->y));
	return (ratio);
}

#include <stdio.h>

void so_cpy_image(t_so *so, t_sosprite_data *dest, t_sosprite_data *src)
{
	int i;
	int j;

	if (!src || !dest)
	{
		dest = NULL;
		return ;
	}
	t_sovec2 *ratio;
	// size_si_origin_dois_etre_mis_sans_redimentionné l'imag
	t_sovec2 *size_redem;


	//utilise source pour...


	ratio = calculate_ratio_size(so, dest, src, &size_redem);
	printf(" ------------ ( %d --- %d ) ( %d --- %d )------------\n", dest->size->width, dest->size->height, src->size->width, src->size->height);
	printf("---- %02f --- %02f --()-- %02f --- %02f ------\n", ratio->x, ratio->y, size_redem->x, size_redem->y);
	i = 0;
	while (i < dest->size->height)
	{
		j = 0;
		while (j < dest->size->width)
		{
			solib_write_pixel(dest, j, i, solib_get_pixel(src, j / ratio->x, i / ratio->y));
			j++;
		}
		i++;
	}
}

void	so_put_on_grid(t_sosprite *dest, t_sosprite *src)
{
	int i;
	int j;

	if (!src || !dest)
		return ;
	i = 0;
	j = 0;
	printf(" - so->grid->area[i][j]  -- %f -- %f | %d -- %d\n",  src->transform->origin->x, src->transform->origin->y, src->transform->size->width, src->transform->size->height);
	while (i < src->transform->size->height)
	{
		j = 0;
		while (j < src->transform->size->width)
		{
			solib_write_pixel(dest->data, j + (int)src->transform->origin->x, i + (int)src->transform->origin->y, solib_get_pixel(src->data, j, i));
			j++;
		}
		i++;
	}
}
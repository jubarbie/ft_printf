/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/14 15:26:39 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepend(char *s1, char *s2)
{
	char *s3;

	if (s1 != NULL && s2 != NULL)
	{
		s3 = ft_strjoin(s1, s2);
		free(s2);
		return (s3);
	}
	return (NULL);
}

char	*str_joinfree(char *s1, char *s2)
{
	char	*s3;

	if (s1 != NULL && s2 != NULL)
	{
		s3 = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
		return (s3);
	}
	return (NULL);
}

char	*str_repeat(char c, int len)
{
	char	*str;

	if ((str = ft_strnew(len)) != NULL)
	{
		while (--len >= 0)
			str[len] = c;
	}
	return (str);
}

char	*padding(char *str, char c, int size, char right)
{
	char	*new;
	char	*fill;
	int		len;
	
	if (str == NULL)
		return (NULL);
	len = size - ft_strlen(str);
	if (len <= 0)
		return (str);
	fill = str_repeat(c, len);
	new = (right == 0) ? ft_strjoin(fill, str) : ft_strjoin(str, fill);
	free(fill);
	free(str);
	return (new);
}

char	*int_conversions(long long int data, t_opt *o)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_itoa_opt(data, o->prec)) == NULL)
		return (NULL);
	if (o->conv == 'i' || o->conv == 'd' || o->conv == 'u')
	{
		if (*s1 != '-' && o->flags & F_PLU)
		{
			s2 = prepend("+", s1);
			s1 = s2;
		}
		else if (*s1 != '-' && o->flags & F_SPA)
		{
			s2 = prepend(" ", s1);
			s1 = s2;
		}
		s2 = padding(s1, ' ', o->width, (o->flags & F_MIN));
		return (s2);
	}
	if (o->conv == 'o' || o->conv == 'x' || o->conv == 'X')
	{
		s2 = ft_convert_base(s1, B_D, (o->conv == 'o') ? B_O : B_H);
		free(s1);
		s1 = padding(s2, '0', o->prec, (o->flags & F_MIN));
		if (o->flags & F_ALT)
		{
			if (o->conv == 'o')
				s2 = (*s1 != '0') ? prepend("0", s1) : s1;
			else if (!ft_strequ("0", s1))
				s2 = prepend("0x", s1);
			s1 = s2;
		}
		if (o->conv == 'X')
		{
			s2 = ft_strmap(s1, &ft_toupper);
			free(s1);
			s1 = s2;
		}
		s2 = padding(s1, ' ', o->width, (o->flags & F_MIN));
		return (s2);
	}
	return (NULL);
}

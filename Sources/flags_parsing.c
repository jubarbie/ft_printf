/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:08:55 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 14:07:15 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char *str, char *f)
{
	int	i;
	int	j;

	*f = 0;
	i = 0;
	while (ft_strchr(FLAGS, str[i]) != NULL)
	{
		j = 0;
		while (FLAGS[j])
		{
			if (*str == FLAGS[j])
				*f |= (1 << j);
			j++;
		}
		i++;
	}
	return (i);
}

int		get_width(char *str, int *p)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	*p = ft_atoi(str);
	return (i);
}

int		get_prec(char *str, int *w)
{
	int	i;

	i = 0;
	*w = 0;
	if (str[i] != '.')
		return (0);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	*w = ft_atoi(str + 1);
	return (i);
}

int		get_modif(char *str, char *m)
{
	int	i;
	int	j;

	i = 0;
	*m = 0;
	if (ft_strchr(MOD, str[i]) != NULL)
	{
		j = 0;
		while (MOD[j])
		{
			if (str[i] == MOD[j])
				*m |= (1 << (j + ((str[i] == str[i + 1]) ? 4 : 0)));
			j++;
		}
		i += (*m >= M_HH) ? 2 : 1;
	}
	return (i);
}

char	*get_options(char *str, char **ret, va_list ap)
{
	int		i;
	t_opt	opt;

	i = 0;
	if (!str[i] || str[i] != '%')
		return (str);
	i = 1;
	if (str[i] == '%')
	{
		*ret = ft_strdup("%");
		return (str + 2);
	}
	i += get_flags(&str[i], &(opt.flags));
	i += get_width(&str[i], &(opt.width));
	i += get_prec(&str[i], &(opt.prec));
	i += get_modif(&str[i], &(opt.modif));
	opt.conv = str[i];
	convert(ret, ap, &opt);
	i++;
	if (i == 1)
		*ret = ft_strdup("");
	return (str + i);
}

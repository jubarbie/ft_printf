/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:08:55 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/12 15:04:29 by jubarbie         ###   ########.fr       */
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
		}
		i++;
	}
	return (i);
}

int	get_prec(char *str, int	*p)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i > 0)
		*p = ft_atoi(str);
	else
		*p = 0;
	return (i);
}

int	get_width(char *str, int *w)
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
	i += get_prec(&str[i], &(opt.prec));
	i += get_width(&str[i], &(opt.width));
	if (ft_strchr(MOD, str[i]) != NULL)
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			i++;
		if (str[i] == 'l' && str[i + 1] == 'l')
			i++;
		i++;
	}
	opt.conv = str[i];
	if (ft_strchr(CONV_INT, str[i]) != NULL)
		*ret = int_conversions(va_arg(ap, int), &opt);
	if (ft_strchr(CONV_CHAR, str[i]) != NULL)
		*ret = char_conversion(va_arg(ap, char), &opt);
	if (ft_strchr(CONV_STR, str[i]) != NULL)
		*ret = str_conversion(va_arg(ap, char *), &opt);
	i++;
	if (i == 1)
		*ret = ft_strdup("");
	return (str + i);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:08:55 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/14 15:24:31 by jubarbie         ###   ########.fr       */
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

int	get_width(char *str, int *p)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	*p = ft_atoi(str);
	return (i);
}

int	get_prec(char *str, int *w)
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

int get_modif(char *str, char *m)
{
	int	i;

	i = 0;
	*m = 0;
	if (ft_strchr(MOD, str[i]) != NULL)
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			*m |= M_HH;
			i++;
		}
		else if (str[i] == 'l' && str[i + 1] == 'l')
		{	
			i++;
			*m |= M_LL;
		}
		else if (*str == 'h')
			*m = M_H;
		else if (*str == 'l')
			*m = M_L;
		else if (*str == 'j')
			*m = M_J;
		else if (*str == 'z')
			*m = M_Z;
		i++;
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
	if (ft_strchr(CONV_INT, str[i]) != NULL)
	{
		if (opt.conv == 'u' || opt.conv == 'U')
		{
			if (opt.modif & M_LL)
				*ret = int_conversions(va_arg(ap, unsigned long long int), &opt);
			else if (opt.modif & M_L || opt.modif & M_J)
				*ret = int_conversions(va_arg(ap, unsigned long int), &opt);
			else	
				*ret = int_conversions(va_arg(ap, unsigned int), &opt);
		}
		if (opt.modif & M_LL)
			*ret = int_conversions(va_arg(ap, long long int), &opt);
		else if (opt.modif & M_L || opt.modif & M_J)
			*ret = int_conversions(va_arg(ap, long int), &opt);
		else	
			*ret = int_conversions(va_arg(ap, int), &opt);
	}
	if (ft_strchr(CONV_CHAR, str[i]) != NULL)
		*ret = char_conversion(va_arg(ap, int), &opt);
	if (ft_strchr(CONV_STR, str[i]) != NULL)
		*ret = str_conversion(va_arg(ap, char *), &opt);
	i++;
	if (i == 1)
		*ret = ft_strdup("");
	return (str + i);
}



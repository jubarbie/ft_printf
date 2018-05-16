/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:23:41 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 14:05:21 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_args(const char *restrict str)
{
	int		i;
	int		nb_args;

	i = -1;
	nb_args = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			nb_args++;
	}
	return (nb_args);
}

char	*get_segment(char *str, char **ret, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == '%')
		return (get_options(str, ret, ap));
	while (str[i] && str[i] != '%')
		i++;
	*ret = ft_strnew(i);
	ft_strncpy(*ret, str, i);
	return (str + i);
}

int		parse_format(char ***arr, const char *restrict format, va_list ap)
{
	int		nb_args;
	char	*str;
	int		i;

	nb_args = get_nb_args(format);
	*arr = (char **)malloc(sizeof(char *) * (nb_args + 1) * 2);
	if (*arr != NULL)
	{
		i = 0;
		while (i < (nb_args + 1) * 2)
			(*arr)[i++] = NULL;
		str = (char *)format;
		i = 0;
		while (*str)
		{
			str = get_segment(str, &((*arr)[i]), ap);
			i++;
		}
		return (nb_args);
	}
	return (-1);
}

int		ft_printf(const char *restrict format, ...)
{
	int		nb;
	va_list	ap;
	char	*str;
	char	**arr;

	va_start(ap, format);
	nb = parse_format(&arr, format, ap);
	if (arr == NULL)
		return (-1);
	str = join_array(arr, (nb + 1) * 2);
	if (str == NULL)
		return (-1);
	ft_putstr(str);
	free(arr);
	va_end(ap);
	return (ft_strlen(str));
}

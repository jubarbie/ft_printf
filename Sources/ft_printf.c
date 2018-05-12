/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:23:41 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/12 14:52:08 by jubarbie         ###   ########.fr       */
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

void	print_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		ft_putendl(arr[i]);
}

int	parse_format(char ***arr, const char *restrict format, va_list ap)
{
	int		nb_args;	
	char	*str;
	int		i;

	nb_args = get_nb_args(format);
	*arr = (char **)malloc(sizeof(char *) * (nb_args + 1) * 2);
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
	//print_array(*arr);
	return (nb_args);
}

int	ft_printf(const char *restrict format, ...)
{
	int		nb;
	va_list	ap;
	char	*str;
	char	**arr;
	int		len;
	int		i;

	va_start(ap, format);
	nb = parse_format(&arr, format, ap);
	len = 0;
	i = 0;
	str = *arr;
	while (i < (nb + 1) * 2)
	{
		if (str != NULL)
		{
			ft_putstr(str);
			len += ft_strlen(str);
			free(str);
		}
		str = arr[++i];
	}
	free(arr);
	va_end(ap);
	return (len);
}

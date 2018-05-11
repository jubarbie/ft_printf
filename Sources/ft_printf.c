/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:23:41 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/11 18:53:47 by jubarbie         ###   ########.fr       */
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

char	*get_options(char *str, char **ret, va_list ap)
{
	int		i;

	i = 0;
	if (!str[i] || str[i] != '%')
		return (str);
	i = 1;
	if (str[i] == '%')
	{
		*ret = ft_strdup("%");
		return (str + 2);
	}
	if (ft_strchr(FLAGS, str[i]) != NULL)
		i++;
	while (ft_isdigit(str[i]) != 0)
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]) != 0)
		i++;
	if (ft_strchr(MOD, str[i]) != NULL)
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			i++;
		if (str[i] == 'l' && str[i + 1] == 'l')
			i++;
		i++;
	}
	if (ft_strchr(CONV, str[i]) != NULL)
	{
		if (str[i] == 's')
			*ret = ft_strdup(va_arg(ap, char *));
		i++;
	}
	if (i == 1)
		*ret = ft_strdup("");
	*ret = ft_strnew(i);
	ft_strncpy(*ret, str, i);
	return (str + i);
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

char	**parse_format(const char *restrict format, va_list ap)
{
	char	**ret;
	int		nb_args;	
	char	*str;
	int		i;

	nb_args = get_nb_args(format);
	ret = (char **)malloc(sizeof(char *) * (nb_args + 1) * 2);
	i = 0;
	while (i < (nb_args + 1) * 2)
		ret[i++] = NULL;
	str = (char *)format;
	i = 0;
	while (*str)
	{
		str = get_segment(str, &ret[i], ap);
		i++;
	}
	print_array(ret);
	return (ret);
}

int	ft_printf(const char *restrict format, ...)
{
	int		nb_args;
	va_list	ap;
	char	*str;
	char	**arr;
	int		len;

	arr = parse_format(format, ap);
	va_start(ap, format);
	len = 0;
	while (*arr)
	{
		if (**arr == '%')
			//str = va_arg(ap, char *);
			ft_putstr(*arr);
		else
			ft_putstr(*arr);
		len += ft_strlen(*arr);
		arr++;
	}
	va_end(ap);
	return (len);
}

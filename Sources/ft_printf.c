/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:23:41 by jubarbie          #+#    #+#             */
/*   Updated: 2018/04/27 18:54:16 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_input(char *str)
{
	int	i;
	int	nb_args;

	nb_args = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			nb_args++;
	}
	return nb_args;
}

int	ft_printf(const char * restrict format, ...)
{
	int		nb_args;
	int		max;
	va_list	ap;

	nb_args = parse_input(format);
	va_start(ap, nb_args);
	max = va_arg(ap, int)
	return (0);
}

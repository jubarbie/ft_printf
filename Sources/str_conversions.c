/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:05:08 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/12 15:05:05 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_conversion(int c, t_opt *opt)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (char)c;
	return (str);
}

char	*str_conversion(char *str, t_opt *otp)
{
	return (ft_strdup(str));
}

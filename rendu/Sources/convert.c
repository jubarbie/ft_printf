/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:04:48 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 17:42:11 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(char **ret, va_list ap, t_opt *o)
{
	if (ft_strchr(CONV_USIGN, o->conv) != NULL)
	{
		if (o->modif & M_LL)
			*ret = unsigned_conversions(va_arg(ap, long long unsigned), o);
		else if (o->modif & M_L || o->modif & M_J)
			*ret = unsigned_conversions(va_arg(ap, long unsigned int), o);
		else
		    *ret = unsigned_conversions(va_arg(ap, unsigned int), o);
	}
	if (ft_strchr(CONV_SIGN, o->conv) != NULL)
	{
		if (o->modif & M_LL)
			*ret = signed_conversions(va_arg(ap, long long int), o);
		else if (o->modif & M_L || o->modif & M_J)
			*ret = signed_conversions(va_arg(ap, long int), o);
		else
			*ret = signed_conversions(va_arg(ap, int), o);
	}
	if (ft_strchr(CONV_CHAR, o->conv) != NULL)
		*ret = char_conversion(va_arg(ap, int), o);
	if (ft_strchr(CONV_STR, o->conv) != NULL)
		*ret = str_conversion(va_arg(ap, char *), o);
}

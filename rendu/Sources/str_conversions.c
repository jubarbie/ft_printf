/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:05:08 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 15:27:12 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_conversion(int c, t_opt *o)
{
	char	*str;
	char	*s1;

	if (o->conv == 'C' || o->modif & M_L)
		str = wchar(c);
	else
	{
		str = ft_strnew(1);
		if (str == NULL)
		    return (NULL);
		str[0] = (char)c;
	}
	s1 = padding(str, ' ', o->width, (o->flags & F_MIN));
    free(str);
	return (s1);
}

char	*str_conversion(char *str, t_opt *o)
{
	char	*s1;
	char	*s2;

    if (str == NULL)
        return (ft_strdup("(null)"));
	s1 = ft_strdup(str);
	if (s1 == NULL)
		return (NULL);
	s2 = padding(s1, cpad(*o), o->width, (o->flags & F_MIN));
    free(s1);
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 14:46:31 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_conversions(long long int data, t_opt *o)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_itoa_opt(data)) == NULL)
		return (NULL);
	if (o->conv == 'i' || o->conv == 'd')
	{
		if (*s1 != '-' && o->flags & F_PLU)
		{
			s2 = prepend("+", s1);
            free(s1);
			s1 = s2;
		}
		else if (*s1 != '-' && o->flags & F_SPA)
		{
			s2 = prepend(" ", s1);
            free(s1);
			s1 = s2;
		}
		s2 = padding(s1, cpad(*o), o->width, (o->flags & F_MIN));
        free(s1);
		return (s2);
	}
	return (NULL);
}

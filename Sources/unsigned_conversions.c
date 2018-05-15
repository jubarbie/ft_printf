/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 14:38:46 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	toupper(char c)
{
	return ((char)ft_toupper((int)c));
}

char		*change_base(char *s1, t_opt *o)
{
	char	*s2;

	s2 = ft_convert_base(s1, B_D, (o->conv == 'o') ? B_O : B_H);
	free(s1);
	s1 = padding(s2, '0', o->prec, (o->flags & F_MIN));
	if (o->flags & F_ALT)
	{
		if (o->conv == 'o')
			s2 = (*s1 != '0') ? prepend("0", s1) : s1;
		else if (!ft_strequ("0", s1))
			s2 = prepend("0x", s1);
		s1 = s2;
	}
	if (o->conv == 'X')
	{
		s2 = ft_strmap(s1, &toupper);
		free(s1);
		s1 = s2;
	}
	return (s1);
}

char		*unsigned_conversions(unsigned long long int data, t_opt *o)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_uitoa_opt(data, o->prec)) == NULL)
		return (NULL);
	if (o->conv == 'o' || o->conv == 'x' || o->conv == 'X')
		s1 = change_base(s1, o);
	s2 = padding(s1, ' ', o->width, (o->flags & F_MIN));
	return (s2);
}

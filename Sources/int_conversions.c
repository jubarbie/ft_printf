/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/12 15:00:10 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_conversions(int data, t_opt *o)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_itoa(data)) == NULL)
		return (NULL);
	if (o->conv == 'i' || o->conv == 'd')
		return (s1);
	if (o->conv == 'o' || o->conv == 'x' || o->conv == 'X')
	{
		s2 = ft_convert_base(s1, B_D, (o->conv == 'o') ? B_O : B_H);
		free(s1);
		return (s2);
	}
	return (NULL);
}

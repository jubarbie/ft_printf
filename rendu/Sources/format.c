/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:54:07 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 15:25:48 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepend(char *s1, char *s2)
{
	char *s3;

	if (s1 != NULL && s2 != NULL)
	{
		s3 = ft_strjoin(s1, s2);
		free(s2);
		return (s3);
	}
	return (NULL);
}

char	*padding(char *str, char c, int size, char right)
{
	char	*new;
	char	*fill;
	int		len;

	if (str == NULL)
		return (NULL);
	len = size - ft_strlen(str);
	if (len <= 0)
		return (str);
	fill = ft_strrepeat(c, len);
	new = (right == 0) ? ft_strjoinfree(fill, str) : ft_strjoinfree(str, fill);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tohex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:53:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 18:43:03 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	bitlen(unsigned long long int nb)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (i < (int)(sizeof(unsigned long long int)))
	{
		j = 0;
		if (nb & (1 << i))
			len = i + 1;
		i++;
	}
	return (len);
}

char		*tohex(unsigned long long int nb)
{
	int		len;
	char	*str;
	int		i;
	int		j;
	int		b;

	len = bitlen(nb);
	len = len / 4 + ((len % 4 > 0) ? 1 : 0);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		j = -1;
		b = 0;
		while (++j < 4)
			if (nb & (1 << ((4 * i) + j)))
				b |= (1 << j);
		str[i] = b + 48;
	}
	return (str);
}

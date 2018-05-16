/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_converstion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 10:45:59 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 12:30:45 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define B1 "0xxxxxxx"
#define B2 "110xxxxx10xxxxxx"
#define B3 "1110xxxx10xxxxxx10xxxxxx"
#define B4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"

int		set_bit(char *c, char mask, int j, int i, unsigned int nb)
{
	if (mask == '1')
		*c |= (1 << (j % 8));
	else if (mask == '0')
		*c &= ~(1 << (j % 8));
	else
	{
		if (nb & (1 << i))
			*c |= (1 << (j % 8));
		else
			*c &= ~(1 << (j % 8));
		i++;
	}
	return (i);
}

char	*apply_mask(char *mask, unsigned int nb)
{
	int		len;
	int		i;
	int		j;
	char	*c;

	len = ft_strlen(mask);
	c = ft_strnew(len / 8);
	if (c == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (--len >= 0)
		i = set_bit(&c[len / 8], mask[len], j++, i, nb);
	return (c);
}

int		bitlen(unsigned int nb)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < (int)(sizeof(unsigned int) * 8))
	{
		if (nb & (1 << i))
			len = i + 1;
		i++;
	}
	return (len);
}

void	printbit(char *str)
{
	int i;

	while (*str)
	{
		i = -1;
		while (++i < 8)
			if (*str & (1 << i))
				ft_putchar('1');
			else
				ft_putchar('0');
		ft_putchar(' ');
		str++;
	}
}

char	*wchar(wchar_t c)
{
	int		len;
	char	*wchar;

	len = bitlen((unsigned int)c);
	if (len <= 7)
		wchar = apply_mask(B1, c);
	else if (len <= 11)
		wchar = apply_mask(B2, c);
	else if (len <= 16)
		wchar = apply_mask(B3, c);
	else
		wchar = apply_mask(B4, c);
	return (wchar);
}

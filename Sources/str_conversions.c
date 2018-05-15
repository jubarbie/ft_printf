/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:05:08 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 18:59:07 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define B1 "0xxxxxxx"
#define B2 "110xxxxx10xxxxxx"
#define B3 "1110xxxx10xxxxxx10xxxxxx"
#define B4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"

char	*apply_mask(char *c, char *mask, unsigned int nb)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(mask);
	i = 0;
	j = 0;
	while (--len >= 0)
	{
		if (mask[len] == '1')
			c[len/8] |= (1 << (j % 8));
		else if (mask[len] == '0')
			c[len/8] &= ~(1 << (j % 8));
		else
		{
			if (nb & (1 << i))
				c[len/8] |= (1 << (j % 8));
			else 
				c[len/8] &= ~(1 << (j % 8));
			i++;
		}
		j++;
	}
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
				printf("1");
			else
				printf("0");
		printf(" ");
		str++;
	}
}
char	*wchar(wchar_t c)
{
	int		len;
	char	*wchar;

	len = bitlen((unsigned int)c);
	wchar = NULL;
	if (len <= 7)
	{
		wchar = ft_strnew(1);
		apply_mask(wchar, B1, c);
	}
	else if (len <= 11)
	{
		wchar = ft_strnew(2);
		apply_mask(wchar, B2, c);
	}
	else if (len <= 16)
	{
		wchar = ft_strnew(3);
		apply_mask(wchar, B3, c);
	}
	else
	{
		wchar = ft_strnew(4);
		apply_mask(wchar, B4, c);
	}
	printbit(wchar);
	printf("\nlen: %d\n", len);
	return (wchar);
}

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
	return (s1);
}

char	*str_conversion(char *str, t_opt *o)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup(str);
	if (s1 == NULL)
		return (NULL);
	s2 = padding(s1, ' ', o->width, (o->flags & F_MIN));
	return (s1);
}

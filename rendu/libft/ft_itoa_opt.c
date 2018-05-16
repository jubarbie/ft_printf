/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 20:38:28 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 11:59:12 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_nbrlen(long long int n)
{
	if (n == 0)
		return (0);
	return (1 + ft_nbrlen(n / 10));
}

static long long int	ft_llpower(long long int n, int power)
{
	long long int res;

	res = n * n;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	if (power > 2)
		res = n * (ft_llpower(n, --power));
	return (res);
}

static char				*do_itoa(char *str, long long int n, int len, int prec)
{
	char			*ps;
	long long int	dig;

	ps = str;
	if (n == 0)
		*str = '0';
	if (n < 0)
	{
		*ps++ = '-';
		len--;
		n = n * -1;
	}
	while (prec-- - len > 0)
		*ps++ = '0';
	while (len-- > 0)
	{
		dig = n / ft_llpower(10, len);
		*ps++ = dig + (long long int)48;
		n = n % ft_llpower(10, len);
	}
	return (str);
}

static char				*itoa_min(int prec)
{
	char	*str;
	char	*ps;

	str = ft_strnew((prec > 19) ? prec + 1 : 20);
	if (str == NULL)
		return (NULL);
	*str = '-';
	ps = str + 1;
	while (prec-- - 10 > 0)
		*ps++ = '0';
	ft_strcpy(ps, "9223372036854775808");
	return (str);
}

char					*ft_itoa_opt(long long int n, int prec)
{
	int				len;
	char			*str;

	if (n == -9223372036854775807)
		return (itoa_min(prec));
	str = NULL;
	len = (n == 0) ? 1 : ft_nbrlen(n);
	len = (prec > len) ? prec : len;
	len += (n < 0) ? 1 : 0;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	return (do_itoa(str, n, len, prec));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 20:38:28 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 12:04:25 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned long long int	t_ull;

static size_t	ft_nbrlen(t_ull n)
{
	if (n == 0)
		return (0);
	return (1 + ft_nbrlen(n / 10));
}

static t_ull	ft_llpower(unsigned long long n, int power)
{
	unsigned long long int res;

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

static char		*do_itoa(char *str, t_ull n, int len, int prec)
{
	char	*ps;
	t_ull	dig;

	ps = str;
	if (n == 0)
		*str = '0';
	while (prec-- - len > 0)
		*ps++ = '0';
	while (len-- > 0)
	{
		dig = n / ft_llpower(10, len);
		*ps++ = dig + 48;
		n = n % ft_llpower(10, len);
	}
	return (str);
}

char			*ft_uitoa_opt(t_ull n, int prec)
{
	int		len;
	char	*str;

	str = NULL;
	len = ft_nbrlen(n);
	str = ft_strnew((prec > len) ? prec : len);
	if (str == NULL)
		return (NULL);
	return (do_itoa(str, n, len, prec));
}

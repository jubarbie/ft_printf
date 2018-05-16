/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:46:20 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 10:36:18 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepeat(char c, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)) != NULL)
	{
		while (len > 0)
			str[--len] = c;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:51:39 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/24 14:42:18 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*pdst;

	pdst = dst;
	while (*src != '\0' && len > 0)
	{
		*pdst = *src;
		pdst++;
		src++;
		len--;
	}
	if (len > 0)
		while (len > 0)
		{
			*pdst = '\0';
			pdst++;
			len--;
		}
	return (dst);
}

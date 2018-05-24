/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:46:18 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/24 14:41:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*pdst;

	pdst = dst;
	while (*src != '\0')
	{
		*pdst = *src;
		src++;
		pdst++;
	}
	*pdst = '\0';
	return (dst);
}

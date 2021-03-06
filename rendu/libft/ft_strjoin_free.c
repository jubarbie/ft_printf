/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:15:35 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/16 15:27:12 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*tmp;

	tmp = (char *)s1;
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	return ((char *)s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:15:02 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/24 15:21:55 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		ft_putendl(arr[i]);
}

int		len_array(char **arr, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i])
			len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

char	*join_array(char **arr, int size)
{
	int		len;
	char	*str;
	char	*ps;
	int		i;

	len = len_array(arr, size);
	str = ft_strnew(len);
	i = 0;
	ps = str;
	while (i < size)
	{
		if (arr[i])
		{
			ft_strcpy(ps, arr[i]);
			ps += ft_strlen(arr[i]);
			free(arr[i]);
		}
		i++;
	}
	return (str);
}

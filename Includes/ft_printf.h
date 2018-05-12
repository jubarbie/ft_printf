/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:18:31 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/12 15:05:19 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> 
# include "libft.h"

# define FLAGS "#0-+ "
# define CONV_INT "dDioOuUxX"
# define CONV_STR "sS"
# define CONV_CHAR "cC"
# define MOD "hljz"
# define B_D "0123456789"
# define B_O "01234567"
# define B_H "0123456789ABCDEF"
# define F_ALT (1 << 0)
# define F_ZER (1 << 1)
# define F_MIN (1 << 2)
# define F_PLU (1 << 3)
# define F_SPA (1 << 4)

typedef struct s_opt {
	char	flags;
	int		prec;
	int		width;
	char	conv;
} t_opt;

int		ft_printf(const char * restrict format, ...);
char	*get_options(char *str, char **ret, va_list ap);
char	*int_conversions(int data, t_opt *opt);
char	*char_conversion(int data, t_opt *opt);
char	*str_conversion(char *data, t_opt *opt);

#endif

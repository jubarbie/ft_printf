/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:18:31 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/15 14:05:15 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define FLAGS "#0-+ "
# define CONV_SIGN "dDi"
# define CONV_USIGN "oOuUxX"
# define CONV_STR "sS"
# define CONV_CHAR "cC"
# define MOD "hljz"
# define B_D "0123456789"
# define B_O "01234567"
# define B_H "0123456789abcdef"
# define F_ALT (1 << 0)
# define F_ZER (1 << 1)
# define F_MIN (1 << 2)
# define F_PLU (1 << 3)
# define F_SPA (1 << 4)
# define M_H (1 << 0)
# define M_L (1 << 1)
# define M_J (1 << 2)
# define M_Z (1 << 3)
# define M_HH (1 << 4)
# define M_LL (1 << 5)

typedef struct	s_opt {
	char	flags;
	int		prec;
	int		width;
	char	modif;
	char	conv;
}				t_opt;

int				ft_printf(const char *restrict format, ...);
char			*get_options(char *str, char **ret, va_list ap);
char			*signed_conversions(long long int data, t_opt *opt);
char			*unsigned_conversions(unsigned long long int data, t_opt *opt);
char			*char_conversion(int data, t_opt *opt);
char			*str_conversion(char *data, t_opt *opt);
char			*prepend(char *s1, char *s2);
char			*padding(char *str, char c, int size, char right);
void			print_array(char **arr);
int				len_array(char **arr, int size);
char			*join_array(char **arr, int size);
void			convert(char **ret, va_list ap, t_opt *o);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:40 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/24 11:30:19 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	char_toupper(char c)
{
	return ((char)ft_toupper((int)c));
}

static char *add_alt(char *s1, t_opt *o)
{
    char    *str;

    if (o->flags & F_ALT)
    {
        if ((o->conv == 'o' || o->conv == 'O') && *s1 != '0')
            str = prepend("0", s1);
	    else if ((o->conv == 'x' || o->conv == 'X') && !ft_strequ("0", s1) && o->prec != 0)
            str = prepend("0x", s1);
        else
            str = ft_strdup(s1);
    } 
    else
        str = ft_strdup(s1);
    return (str);

}

static char *precision(char *str, t_opt *o)
{
    char    *s1;
    int     len;

    len = ft_strlen(str);
    if (o->prec == 0)
        s1 = ft_strdup("");
	else if (o->prec < 0 || len >= o->prec)
        s1 = ft_strdup(str);
    else
        s1 = padding(str, '0', o->prec, 0);
    return (s1);
}

static char *min_width(char *str, t_opt *o)
{
    char    *ret;

    ret = padding(str, cpad(*o), o->width, (o->flags & F_MIN));
    return (ret);
}

static char	*format_result(char *str, t_opt *o)
{
	char	*s1;
    char    *s2;
    
    s1 = precision(str, o);
    s2 = add_alt(s1, o);
    free(s1);
    s1 = min_width(s2, o);
    free(s2);
	if (o->conv == 'X' && s2 != NULL)
	{
		s2 = ft_strmap(s1, &char_toupper);
        free(s1);
		s1 = s2;
	}
	return (s1);
}

char		*unsigned_conversions(unsigned long long int data, t_opt *o)
{
	char	*s1;
	char	*s2;

	if (o->conv == 'o' || o->conv == 'O')
    {
	    s1 = ft_uitoa_opt(data);
        if (s1 == NULL)
            return (NULL);
	    s2 = ft_convert_base(s1, B_D, B_O);
        free(s1);
        s1 = s2;
    }
    else if (o->conv == 'x' || o->conv == 'X')
		s1 = tohex(data);
    else
	    s1 = ft_uitoa_opt(data);
    if ((o->conv == 'x' || o->conv == 'X') && (o->flags & F_ALT) && (o->flags & F_ZER) && !(o->flags & F_MIN))
        o->prec = o->width - 2;
    s2 = format_result(s1, o);
    free(s1);
	return (s2);
}

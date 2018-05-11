/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:18:31 by jubarbie          #+#    #+#             */
/*   Updated: 2018/05/11 17:38:56 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> 
# include "libft.h"

# define FLAGS "#0-+ "
# define CONV "sSpdDioOuUxXcC"
# define MOD "hljz"

int	ft_printf(const char * restrict format, ...);

#endif

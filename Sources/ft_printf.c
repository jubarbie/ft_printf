#include "ft_printf.h"

int	ft_printf(const char * restrict format, ...)
{
	int	ret;
	
	ret = ft_strlen(format);
	ft_putstr(format);
	return (ret);
}

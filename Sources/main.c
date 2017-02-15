#include "ft_printf.h"

int	main(void)
{
	char	*str;
	char	*err;
	char	*ok;
	int		a;
	int		b;

	err = ft_strdup("\033[41;30m ERROR \033[0m");
	ok = ft_strdup("\033[42;30m OK \033[0m");
	printf("\033[36mTest 1: Simple string\033[0m\n");
	str = ft_strdup("Voici une phrase de test");
	a = printf("%s", str);
	printf("\n");
	b = ft_printf(str);
	printf("\n");
	printf("%s -> (%d) (%d)\n", (a - b) ? err : ok, a, b) ;
	printf("------FIN------\n");
	free(str);
	free(err);
	free(ok);
	printf("%d\n", 342);
	return (0);
}

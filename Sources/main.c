#include "ft_printf.h"

void	test(char *str, char *test_name)
{
	char	*err;
	char	*ok;
	int		a;
	int		b;

	err = ft_strdup("\033[41;30m ERROR \033[0m");
	ok = ft_strdup("\033[42;30m OK \033[0m");	
	printf("\033[36m%s\033[0m\n", test_name);
	a = printf("%s", str);
	printf("\n");
	b = ft_printf(str);
	printf("\n");
	printf("%s -> (%d) (%d)\n", (a - b) ? err : ok, a, b) ;
	printf("------FIN------\n");
	free(str);
	free(err);
	free(ok);
}

int	main(int argc, char **argv)
{
	printf("%#4.3.lldr\n");
	if (argc == 2)
		ft_printf(argv[1]);
	ft_printf("Je m'appelle %s\n", ft_strdup("Jules Barbier"));
	return (0);
}

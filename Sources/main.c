#include "ft_printf.h"

#define NB_TESTS 9
#define TEST0 "Je m'appelle %s et j'ai %d ans!\n", "Jules Barbier", 32 
#define TEST1 "%d en hexa ça donne: %x\n", 32, 32
#define TEST2 "La lettre %c en decimal c'est %d\n", 'c', 'c'
#define TEST3 "%c%d\n", '1', '1'
#define TEST4 "%d en octal ça donne ceci %o et en alt o %#o et en alt Hex %#x ou %#X\n", 245, 245, 245, 245, 0
#define TEST5 "Preci: %+.5d %0.15d %#.5o et en alt Hex %#.3x\n", 23, 24, 234, 234
#define TEST6 "% .5d\n%0.15d\n%+7i\n%-50.6iYEAH\n", 23, 24, 234, -231
#define TEST7 "l: %ld, ll: %lld, h: %hd, hh: %hhd\nj: %jd, z: %zd\n", -72147483647, (long long int)8987214748647909000, (short)-788, (signed char)78, (intmax_t)23, (size_t)23
#define TEST8 "%u\n", 21

void	test_head(char *name, int i)
{
	ft_printf("\033[36m%s %d\033[0m\n", name, i);
}
void	test_foot(int a, int b)
{
	char	*err;
	char	*ok;
	
	err = ft_strdup("\033[41;30m ERROR \033[0m");
	ok = ft_strdup("\033[42;30m OK \033[0m");	
	ft_printf("%s -> (%d) (%d)\n\n", (a - b) ? err : ok, a, b) ;
	free(err);
	free(ok);
}
void	test(char *name, int i)
{
	int	a;
	int	b;

	test_head(name, i);
	if (i == 0)
		test_foot(printf(TEST0), ft_printf(TEST0));
	if (i == 1)
		test_foot(printf(TEST1), ft_printf(TEST1));
	if (i == 2)
		test_foot(printf(TEST2), ft_printf(TEST2));
	if (i == 3)
		test_foot(printf(TEST3), ft_printf(TEST3));
	if (i == 4)
		test_foot(printf(TEST4), ft_printf(TEST4));
	if (i == 5)
		test_foot(printf(TEST5), ft_printf(TEST5));
	if (i == 6)
		test_foot(printf(TEST6), ft_printf(TEST6));
	if (i == 7)
		test_foot(printf(TEST7), ft_printf(TEST7));
	if (i == 8)
		test_foot(printf(TEST8), ft_printf(TEST8));
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < NB_TESTS)
		test("TEST", i++);
	//while (i < 10)
	//	i = 9;
	return (0);
}

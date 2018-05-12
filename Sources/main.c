#include "ft_printf.h"

#define TEST0 "Je m'appelle %s et j'ai %d ans!\n", "Jules Barbier", 32 
#define TEST1 "%d en hexa ça donne: %x\n", 32, 32
#define TEST2 "La lettre %c en decimal c'est %d\n", 'c', 'c'
#define TEST3 "%c%d", '1', '1'

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
void	test(char *name, int i)
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
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < 4)
		test("TEST", i++);
	while (i < 10)
		i = 9;
	return (0);
}

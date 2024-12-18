#include "libft.h"
#include <stdio.h>

int main()
{
	char *s = "Hello, world!";
	char *result;

	// Cas 1 : start = 0, longueur exacte
	result = ft_formatsubstr(s, 0, 10, ' ');
	printf("Result: '%s'\n", result);
	printf("EXPECTED : 'Hello, wor'\n");
	free(result);

	// Cas 2 : start < 0, padding au début
	result = ft_formatsubstr(s, -3, 10, ' ');
	printf("Result: '%s'\n", result);
	printf("EXPECTED : '   Hello, '\n");
	free(result);

	// Cas 3 : start > 0, padding à la fin
	result = ft_formatsubstr(s, 7, 10, ' ');
	printf("Result: '%s'\n", result);
	printf("EXPECTED : 'word!     '\n");
	free(result);

	return 0;
}

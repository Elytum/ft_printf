#include <unistd.h>
#include <stdio.h>
#include <ft_printf.h>

#define TEST_SAMPLE "%# +-*.*% %i %s\n", 20, 5, 42, "str"

int main(void)
{
	int original, homemade;

	homemade = ft_printf(TEST_SAMPLE);
	original = printf(TEST_SAMPLE);
	printf("\nHomemade: %i\nOriginal: %i\n", homemade, original);

// int i;
// ft_printf("Test: %n", &i); ft_printf("%i\n", i);
// printf("Test: %n", &i); printf("%i\n", i);

	// printf("%i\n", 424242424);
	// printf("% hhi\n", 424242424);
	// printf("%hi\n", 424242424);
	// printf("%h hhi\n", 424242424);
	// printf("%hh hi\n", 424242424);
	// printf("%hhhi\n", 424242424);

// printf("test%   04.20i\n", 42);
// printf("[%# +-20i %c %s]\n", 42, 'a', "lol");
// printf("[%20# +-30 10.0*f %c %s]\n", 50, 1.23456789, 'a', "lol");
	// printf("%-#10x\n", 42);
	// printf("Value: %i, char: %c, string: %s\n", 42, 'c', "str");
	// ft_printf("Value: %i, char: %c, string: %s\n", 42, 'c', "str");
}
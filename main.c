#include <unistd.h>
#include <stdio.h>
#include <ft_printf.h>

int main(void)
{
	// printf("%-#10x\n", 42);
	printf("Value: %i, char: %c, string: %s\n", 42, 'c', "str");
	ft_printf("Value: %i, char: %c, string: %s\n", 42, 'c', "str");
}
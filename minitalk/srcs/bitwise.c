#include "../includes/minitalk.h"

int main(void)
{
	int x = 42; // 0010 1010
//	x = x >> 3; // 0000 0101
	ft_printf("new x: %i\n", x);
	int y = 1;
	x = x | y;
	ft_printf("x after | y: %i\n", x);
}



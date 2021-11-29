#include "printf.h"
#include <stdio.h>

int	main(void)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * 1);
	if (p == NULL)
		return (-1);

	// printf("   printf -> %123d <-\n", 1);
	// ft_printf("ft_printf -> %123d <-\n", 1);

	// printf("   printf -> %1d <-\n", 1);
	// ft_printf("ft_printf -> %1d <-\n", 1);

	// printf("   printf -> %5d <-\n", 1);
	// ft_printf("ft_printf -> %5d <-\n", 1);

	//    printf("   printf -> %+10d <-\n", 123);
	// ft_printf("ft_printf -> %+10d <-\n", 123);

	   printf("   printf -> %d %d %d <-\n", 10, 1234567, 1423);
	ft_printf("ft_printf -> %d %d %d <-\n", 10, 1234567, 1423);

	// printf("   printf -> %0d <-\n", 1);
	// ft_printf("ft_printf -> %0d <-\n", 1);

	// printf("   printf -> %-1d <-\n", 1);
	// ft_printf("ft_printf -> %-1d <-\n", 1);

	// printf("   printf -> %-5d <-\n", 1);
	// ft_printf("ft_printf -> %-5d <-\n", 1);

	// printf("   printf -> %-5d <-\n", 123);
	// ft_printf("ft_printf -> %-5d <-\n", 123);

	// printf("   printf -> %-12d <-\n", 123);
	// ft_printf("ft_printf -> %-12d <-\n", 123);

	// printf("   printf -> %12d <-\n", 123);
	// ft_printf("ft_printf -> %12d <-\n", 123);

	free(p);
}
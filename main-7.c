#include "ft-printf-bonus/printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*p;
	int		d;

	p = (char *)malloc(sizeof(char) * 1);
	if (p == NULL)
		return (-1);

	d = 123;

	// printf("   printf -> %123d <-\n", 1);
	// ft_printf("ft_printf -> %123d <-\n", 1);

	// printf("   printf -> %1d <-\n", 1);
	// ft_printf("ft_printf -> %1d <-\n", 1);

	// printf("   printf -> %5d <-\n", 1);
	// ft_printf("ft_printf -> %5d <-\n", 1);

	//    printf("   printf -> %+10d <-\n", 123);
	// ft_printf("ft_printf -> %+10d <-\n", 123);

	//    printf("   printf -> %20.1s <-  \n", "1234567890");
	// ft_printf("ft_printf -> %20.1s <-\n\n", "1234567890");

	//    printf("   printf -> %20.10s <-  \n", "1234567890");
	// ft_printf("ft_printf -> %20.10s <-\n\n", "1234567890");

	//    printf("   printf -> %20.20s <-  \n", "1234567890");
	// ft_printf("ft_printf -> %20.20s <-\n\n", "1234567890");

	//    printf("   printf -> %-20.1s <-  \n", "1234567890");
	// ft_printf("ft_printf -> %-20.1s <-\n\n", "1234567890");

	//    printf("   printf -> %-20.10s <-  \n", "1234567890");
	// ft_printf("ft_printf -> %-20.10s <-\n\n", "1234567890");

	   printf("   printf -> |%05%| <-\n");
	ft_printf("ft_printf -> |%05%| <-\n");

	//    printf("   printf -> %20.1s <-  \n", "");
	// ft_printf("ft_printf -> %20.1s <-\n\n", "");

	//    printf("   printf -> %20.10s <-  \n", "");
	// ft_printf("ft_printf -> %20.10s <-\n\n", "");

	//    printf("   printf -> %20.20s <-  \n", "");
	// ft_printf("ft_printf -> %20.20s <-\n\n", "");

	//    printf("   printf -> %-20.1s <-  \n", "");
	// ft_printf("ft_printf -> %-20.1s <-\n\n", "");

	//    printf("   printf -> %-20.10s <-  \n", "");
	// ft_printf("ft_printf -> %-20.10s <-\n\n", "");

	//    printf("   printf -> %-20.20s <-  \n", "");
	// ft_printf("ft_printf -> %-20.20s <-\n\n", "");



	//    printf("   printf -> %20.1s <-  \n", 0);
	// ft_printf("ft_printf -> %20.1s <-\n\n", 0);

	//    printf("   printf -> %20.10s <-  \n", 0);
	// ft_printf("ft_printf -> %20.10s <-\n\n", 0);

	//    printf("   printf -> %20.20s <-  \n", 0);
	// ft_printf("ft_printf -> %20.20s <-\n\n", 0);

	//    printf("   printf -> %-20.1s <-  \n", 0);
	// ft_printf("ft_printf -> %-20.1s <-\n\n", 0);

	//    printf("   printf -> %-20.10s <-  \n", 0);
	// ft_printf("ft_printf -> %-20.10s <-\n\n", 0);

	//    printf("   printf -> %-20.20s <-  \n", 0);
	// ft_printf("ft_printf -> %-20.20s <-\n\n", 0);



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

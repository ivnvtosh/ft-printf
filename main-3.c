#include "ft-printf-bonus/printf_bonus.h"
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

	   printf("   printf -> %+10.1d <-  \n", 123);
	ft_printf("ft_printf -> %+10.1d <-\n\n", 123);

	   printf("   printf -> %+10.2d <-  \n", 123);
	ft_printf("ft_printf -> %+10.2d <-\n\n", 123);

	   printf("   printf -> %+10.3d <-  \n", 123);
	ft_printf("ft_printf -> %+10.3d <-\n\n", 123);

	   printf("   printf -> %+10.4d <-  \n", 123);
	ft_printf("ft_printf -> %+10.4d <-\n\n", 123);

	   printf("   printf -> %+10.5d <-  \n", 123);
	ft_printf("ft_printf -> %+10.5d <-\n\n", 123);

	   printf("   printf -> %+10.6d <-  \n", 123);
	ft_printf("ft_printf -> %+10.6d <-\n\n", 123);

	   printf("   printf -> %+10.7d <-  \n", 123);
	ft_printf("ft_printf -> %+10.7d <-\n\n", 123);

	   printf("   printf -> %+10.8d <-  \n", 123);
	ft_printf("ft_printf -> %+10.8d <-\n\n", 123);

	   printf("   printf -> %+10.9d <-  \n", 123);
	ft_printf("ft_printf -> %+10.9d <-\n\n", 123);

	   printf("   printf -> %+10.10d <-  \n", 123);
	ft_printf("ft_printf -> %+10.10d <-\n\n", 123);

	   printf("   printf -> %+20.10d <-  \n", 123);
	ft_printf("ft_printf -> %+20.10d <-\n\n", 123);



	   printf("   printf -> %-10.1d <-  \n", 123);
	ft_printf("ft_printf -> %-10.1d <-\n\n", 123);

	   printf("   printf -> %-10.2d <-  \n", 123);
	ft_printf("ft_printf -> %-10.2d <-\n\n", 123);

	   printf("   printf -> %-10.3d <-  \n", 123);
	ft_printf("ft_printf -> %-10.3d <-\n\n", 123);

	   printf("   printf -> %-10.4d <-  \n", 123);
	ft_printf("ft_printf -> %-10.4d <-\n\n", 123);

	   printf("   printf -> %-10.5d <-  \n", 123);
	ft_printf("ft_printf -> %-10.5d <-\n\n", 123);

	   printf("   printf -> %-10.6d <-  \n", 123);
	ft_printf("ft_printf -> %-10.6d <-\n\n", 123);

	   printf("   printf -> %-10.7d <-  \n", 123);
	ft_printf("ft_printf -> %-10.7d <-\n\n", 123);

	   printf("   printf -> %-10.8d <-  \n", 123);
	ft_printf("ft_printf -> %-10.8d <-\n\n", 123);

	   printf("   printf -> %-10.9d <-  \n", 123);
	ft_printf("ft_printf -> %-10.9d <-\n\n", 123);

	   printf("   printf -> %-10.10d <-  \n", 123);
	ft_printf("ft_printf -> %-10.10d <-\n\n", 123);

	   printf("   printf -> %-20.10d <-  \n", 123);
	ft_printf("ft_printf -> %-20.10d <-\n\n", 123);
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

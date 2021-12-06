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

	   printf("   printf -> %.x <-  \n", d);
	ft_printf("ft_printf -> %.x <-\n\n", d);

	   printf("   printf -> %.1x <-  \n", d);
	ft_printf("ft_printf -> %.1x <-\n\n", d);

	   printf("   printf -> %.2x <-  \n", d);
	ft_printf("ft_printf -> %.2x <-\n\n", d);

	   printf("   printf -> %.3x <-  \n", d);
	ft_printf("ft_printf -> %.3x <-\n\n", d);

	   printf("   printf -> %.4x <-  \n", d);
	ft_printf("ft_printf -> %.4x <-\n\n", d);

	   printf("   printf -> %.5x <-  \n", d);
	ft_printf("ft_printf -> %.5x <-\n\n", d);

	   printf("   printf -> %.6x <-  \n", d);
	ft_printf("ft_printf -> %.6x <-\n\n", d);

	   printf("   printf -> %.7x <-  \n", d);
	ft_printf("ft_printf -> %.7x <-\n\n", d);

	   printf("   printf -> %.8x <-  \n", d);
	ft_printf("ft_printf -> %.8x <-\n\n", d);

	   printf("   printf -> %.9x <-  \n", d);
	ft_printf("ft_printf -> %.9x <-\n\n", d);

	   printf("   printf -> %.10x <-  \n", d);
	ft_printf("ft_printf -> %.10x <-\n\n", d);
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

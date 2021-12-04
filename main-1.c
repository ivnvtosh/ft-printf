#include "ft-printf-bonus/printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*p;
	int		d;

	p = (char *)malloc(sizeof(char) * 1);
	if (p == NULL)
		return (-1);
	
	d = -123;

	// printf("   printf -> %123d <-\n", 1);
	// ft_printf("ft_printf -> %123d <-\n", 1);

	// printf("   printf -> %1d <-\n", 1);
	// ft_printf("ft_printf -> %1d <-\n", 1);

	// printf("   printf -> %5d <-\n", 1);
	// ft_printf("ft_printf -> %5d <-\n", 1);

	//    printf("   printf -> %+10d <-\n", 123);
	// ft_printf("ft_printf -> %+10d <-\n", 123);

	   printf("   printf -> %+d <-  \n", d);
	ft_printf("ft_printf -> %+d <-\n\n", d);

	   printf("   printf -> %+1d <-  \n", d);
	ft_printf("ft_printf -> %+1d <-\n\n", d);

	   printf("   printf -> %+2d <-  \n", d);
	ft_printf("ft_printf -> %+2d <-\n\n", d);

	   printf("   printf -> %+3d <-  \n", d);
	ft_printf("ft_printf -> %+3d <-\n\n", d);

	   printf("   printf -> %+4d <-  \n", d);
	ft_printf("ft_printf -> %+4d <-\n\n", d);

	   printf("   printf -> %+5d <-  \n", d);
	ft_printf("ft_printf -> %+5d <-\n\n", d);

	   printf("   printf -> %+6d <-  \n", d);
	ft_printf("ft_printf -> %+6d <-\n\n", d);

	   printf("   printf -> %+7d <-  \n", d);
	ft_printf("ft_printf -> %+7d <-\n\n", d);

	   printf("   printf -> %+8d <-  \n", d);
	ft_printf("ft_printf -> %+8d <-\n\n", d);

	   printf("   printf -> %+9d <-  \n", d);
	ft_printf("ft_printf -> %+9d <-\n\n", d);

	   printf("   printf -> %+10d <-  \n", d);
	ft_printf("ft_printf -> %+10d <-\n\n", d);



	   printf("   printf -> %+-1d <-  \n", d);
	ft_printf("ft_printf -> %+-1d <-\n\n", d);

	   printf("   printf -> %+-2d <-  \n", d);
	ft_printf("ft_printf -> %+-2d <-\n\n", d);

	   printf("   printf -> %+-3d <-  \n", d);
	ft_printf("ft_printf -> %+-3d <-\n\n", d);

	   printf("   printf -> %+-4d <-  \n", d);
	ft_printf("ft_printf -> %+-4d <-\n\n", d);

	   printf("   printf -> %+-5d <-  \n", d);
	ft_printf("ft_printf -> %+-5d <-\n\n", d);

	   printf("   printf -> %+-6d <-  \n", d);
	ft_printf("ft_printf -> %+-6d <-\n\n", d);

	   printf("   printf -> %+-7d <-  \n", d);
	ft_printf("ft_printf -> %+-7d <-\n\n", d);

	   printf("   printf -> %+-8d <-  \n", d);
	ft_printf("ft_printf -> %+-8d <-\n\n", d);

	   printf("   printf -> %+-9d <-  \n", d);
	ft_printf("ft_printf -> %+-9d <-\n\n", d);

	   printf("   printf -> %+-10d <-  \n", d);
	ft_printf("ft_printf -> %+-10d <-\n\n", d);

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

#include "printf_bonus.h"

static void	process_fill(o_list *flags)
{
	int	width;

	if (flags->fill == 0 || flags->precision)
		flags->fill = ' ';
} 

static void	process_width(o_list *flags, int nlen)
{
	if (flags->width > nlen && flags->width > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width -= flags->precision;
		else
			flags->width -= nlen;
	}
	else if (flags->width * -1 > nlen && flags->width * -1 > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width += flags->precision;
		else
			flags->width += nlen;
	}
	else
		flags->width = 0;
	if (flags->width > 0 && flags->sign)
		flags->width -= 1;
    if (flags->width < 0 && flags->sign)
		flags->width += 1;
}

static void	process_precision(o_list *flags, int nlen)
{
	if (flags->precision > nlen)
		flags->precision = flags->precision - nlen;
	else
		flags->precision = 0;
}

void	process_flags(o_list *flags, unsigned int n)
{
	int	nlen;

	nlen = nbrlen(n, 10);
	process_fill(flags);
	process_width(flags, nlen);
	process_precision(flags, nlen);
}
#include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	i;
}		t_complex

int	main()
{
	t_complex	z;
	t_complex	c;
	double temp_real;

	z.real = 0;
	z.i = 0;
	c.real = 5;
	c.i = 2;

	for (int i = 0; i < 42; ++i)
	{
		temp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = temp_real;

		z.real += c.real;
		z.i += c.i'
	}
}

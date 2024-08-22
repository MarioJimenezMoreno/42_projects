#ifdef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

typedef struct	s_img
{
	void*	img_ptr;
	char*	pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;

typedef struct	s_fractal
{
	char*	name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

}		t_fractal;

#endif

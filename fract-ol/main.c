int	main(int argc, char** argv)
{
	t_fractal	fractal;

	if (argc == 2 && argv[1] == "mandelbrot" || argc == 4 && argv[1] == "julia")
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fracta_render(&fractal);
		mlx_loop(fractal.mlx_conecction);
	}
	else
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
}

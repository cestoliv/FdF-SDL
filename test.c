# include "mlx/mlx.h"

void	draw_square(void *mlx, void *win, int x1, int y1, int x2, int y2, int color)
{
	int y;
	while (x1 < x2)
	{
		y = y1;
		while (y < y2)
		{
			mlx_pixel_put(mlx, win, x1, y, color);
			y++;
		}
		x1++;
	}
}

int	main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 800, 480, "FDF ocartier");

	draw_square(mlx, win, 0, 0, 800, 480, 0xFF0000);
	draw_square(mlx, win, 0, 0, 800, 50, 0xFF00FF);
	int x = 0;
	while (x < 800)
	{
		mlx_pixel_put(mlx, win, x, 1, 0xFFFFFF);
		x++;
	}
	mlx_loop(mlx);
}

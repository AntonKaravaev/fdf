/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/09 18:37:27 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main (int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	int bpp;
	int size_line;
	int endian;
	void *img_ptr;
	char *img_data;
//	int i;
//	char *line;
	int fd;
	//проверки на параметры
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR);
		if (read_file(fd) == 0)
			return (0); //free all
	}
	else
	{
		ft_putstr("Error. Need file.");
		exit(-1);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "anton's fdf");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	ft_memcpy(img_data, draw_line(0, 500, 0, 500, 500, 500), 500 * 500 * 4 * 4);
//	ft_strcpy(img_data, draw_line(0, 150, 0, 100, 500, 500));
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 20, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 30, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 25, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 35, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 45, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 20, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 30, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 40, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 25, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 35, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 40, 45, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 20, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 30, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 40, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 25, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 35, 13132855);
	// mlx_pixel_put(mlx_ptr, win_ptr, 60, 45, 13132855);
	mlx_loop(mlx_ptr);
return (0);
}

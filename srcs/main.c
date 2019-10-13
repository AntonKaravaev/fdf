/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/13 21:53:33 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int main (int argc, char **argv)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	int bpp;
// 	int size_line;
// 	int endian;
// 	void *img_ptr;
// 	char *img_data;
// //	int i;
// //	char *line;
// 	int fd;
// 	//проверки на параметры
// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDWR);
// 		if (read_file(fd) == 0)
// 			return (0); //free all
// 	}
// 	else
// 	{
// 		ft_putstr("Error. Need file.");
// 		exit(-1);
// 	}
// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "anton's fdf");
// 	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
// 	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
// 	ft_memcpy(img_data, draw_line(0, 500, 0, 500, 500, 500), 500 * 500 * 4 * 4);
// //	ft_strcpy(img_data, draw_line(0, 150, 0, 100, 500, 500));
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
// 	mlx_loop(mlx_ptr);
// return (0);
// }

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == kVK_Escape)
		exit (0);
	return (0);
}

void	mlx_initial(t_map  *map)
{
	map->points = NULL;
 	map->str = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
  	map->img_data = NULL;
  	map->img_ptr = NULL;
	map->bpp = 32;
	map->sl = 0;
	map->endian = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "anton's fdf");
	map->img_ptr = (mlx_new_image(map->mlx_ptr, 1000, 1000));
	map->img_data = (int *)(mlx_get_data_addr(map->img_ptr, &map->bpp, &map->sl, &map->endian));
	map->matrix = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->mul_xy = 0;
	map->size_x = 1000;
	map->size_y = 1000;
}

void	ft_validation(char *argv, t_map *map)
{
	int fd;

	if ((fd = open(argv, O_RDWR)) < 0)
	{
		ft_putstr_fd("Error. Incorrect input file.\n", 2);
		exit(-1);
	}
	else if (read_file(map, fd) == 0)
	{
		ft_putstr_fd("Error. Incorrect map.\n", 2);
		exit(-1);
	}
}

int		main(int argc, char **argv)
{
	t_map	map;

	mlx_initial(&map);
	if (argc == 2)
	{
		ft_validation(argv[1], &map);
		ft_solution(&map);
	}
	else
	{
		ft_putstr_fd("Error. Need file.\n", 2);
		exit(-1);
	}


	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.img_ptr, 0, 0);
	mlx_key_hook(map.win_ptr, key_press, (void *)0);
	mlx_loop(map.mlx_ptr);
}

//	mlx_pixel_put(mlx_ptr, win_ptr, 501, 501, 13132855);
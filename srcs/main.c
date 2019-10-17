/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/17 14:08:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_press(int keycode, t_map *map)
{

	//mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_printf(" %d \n ", map->size_x * map->size_y * 4);
	ft_bzero(map->img_data, map->size_x * map->size_y * 4);
	if (keycode == kVK_Escape)
		exit (0);
	else if (keycode == kVK_ANSI_1)
	{
		ft_printf("1\n");
		map->flag2d = 1;
		map->flag3d = 0;
		map->move_vert = 0;
		map->move_horiz = 0;
		map->bors = 1;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_2)
	{
		ft_printf("2\n");
		map->flag2d = 0;
		map->flag3d = 1;
		map->move_vert = 0;
		map->move_horiz = 0;
		map->bors = 1;
		ft_solution(map);
	}
		else if (keycode == kVK_ANSI_3)
	{
		ft_printf("1\n");
		map->flag2d = 1;
		map->flag3d = 0;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_4)
	{
		ft_printf("2\n");
		map->flag2d = 0;
		map->flag3d = 1;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_W)
	{
		ft_printf("W\n");
		map->move_vert -= 10;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_S)
	{
		ft_printf("S\n");
		map->move_vert += 10;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_A)
	{
		ft_printf("A\n");
		map->move_horiz -= 10;
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_D)
	{
		ft_printf("D\n");
		map->move_horiz += 10;
		ft_solution(map);
	}
	else if (keycode == VK_ANSI_KeypadPlus)
	{
		ft_printf("+\n");
		if (map->bors <= 100)
		{
			map->bors += 1;
			ft_printf("++++ Arti = %d\n", map->bors);
		}
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_KeypadMinus)
	{
		ft_printf("-\n");
		if (map->bors >= 2)
		{
			map->bors -= 1;
			ft_printf("Arti-\n");
		}
		ft_solution(map);
	}
	else if (keycode == kVK_ANSI_0)
		print_matrix(map->matrix, map->max_y, map->max_x);

	return (0);
}

// void	move(int key, t_map	*map)
// {
// 	(void)map;
// 	if (kVK_ANSI_P)
// 	// 	fdf->camera->x_offset -= 10;
// 	// else if (key == ARROW_RIGHT)
// 	// 	fdf->camera->x_offset += 10;
// 	// else if (key == ARROW_UP)
// 	// 	fdf->camera->y_offset -= 10;
// 	// else
// 	// 	fdf->camera->y_offset += 10;
// 	ft_solution(map);
// }

static void	mlx_initial(t_map  *map)
{
	map->po = -1;
 	map->str = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
  	map->img_data = NULL;
  	map->img_ptr = NULL;
	map->bpp = 32;
	map->sl = 0;
	map->endian = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1500, 1000, "anton's fdf");
	map->img_ptr = (mlx_new_image(map->mlx_ptr, 1000, 1000));
	map->img_data = (int *)(mlx_get_data_addr(map->img_ptr, &map->bpp, &map->sl, &map->endian));
	map->matrix = NULL;
	map->temp_color = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->mul_xy = 0;
	map->size_x = 1000;
	map->size_y = 1000;
	map->move_vert = 0;
	map->move_horiz = 0;
	map->flag2d = 1;
	map->flag3d = 0;
	map->bors = 1;
}

void		ft_validation(char *argv, t_map *map)
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

int			main(int argc, char **argv)
{
	t_map		map;

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
	ft_printf("map.mul_xy = %d\n", map.mul_xy);
	//mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(map.win_ptr, 2, 0, key_press, &map);
	//mlx_key_hook(map.win_ptr, key_press, &map);
	mlx_loop(map.mlx_ptr);
}


// движение мышки 6
// нажатие на мышки 4
// отпустил 5



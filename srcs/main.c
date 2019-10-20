/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/20 13:04:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_find_the_right_bors(int *bors, int *mul)
{
	if (*mul < 400)
		*bors = 25;
	else if (*mul < 1000)
		*bors = 12;
	else if (*mul < 5000)
		*bors = 3;
	else if (*mul < 10000)
		*bors = 2;
	else if (*mul > 10000)
		*bors = 1;
}

static void	mlx_initial_1(t_map *map)
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
	map->win_ptr = mlx_new_window(map->mlx_ptr,
		WIDTH_OF_WINDOW, HIGH_OF_WINDOW, "anton's fdf");
	map->img_ptr = (mlx_new_image(map->mlx_ptr,
		WIDTH_OF_IMAGE, HIGH_OF_IMAGE));
	map->img_data = (int *)(mlx_get_data_addr(map->img_ptr,
		&map->bpp, &map->sl, &map->endian));
	map->matrix = NULL;
}

static void	mlx_initial_2(t_map *map)
{
	map->temp_color = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->mul_xy = 0;
	map->size_x = 1000;
	map->size_y = 1000;
	map->move_vert = 0;
	map->move_horiz = 0;
	map->pull_z = 0;
	map->iso = 0;
	map->bors = 1;
	map->alfa = 0.0;
	map->beta = 0.0;
	map->gamma = 0.0;
	map->start_pos = 1;
}

static void	ft_validation(char *argv, t_map *map)
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
	t_map	map;

	mlx_initial_1(&map);
	mlx_initial_2(&map);
	if (argc == 2)
	{
		ft_validation(argv[1], &map);
		ft_find_the_right_bors(&map.bors, &map.mul_xy);
		ft_solution(&map);
	}
	else
	{
		ft_putstr_fd("Error. Need file.\n", 2);
		exit(-1);
	}
	mlx_hook(map.win_ptr, 2, 0, key_press, &map);
	mlx_loop(map.mlx_ptr);
}

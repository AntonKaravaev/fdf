/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:25 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/18 01:54:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_fiil_in_point(t_map *map, int i_int, int *co)
{
	int i;
	int j;
	int temp_y;

	i = i_int;
	j = -1;
	temp_y = i;
	while (++j < map->max_x)
	{
		map->points[*co].z = map->matrix[i][j];
		map->points[*co].x = j * map->bors + ((map->size_x - map->max_x * map->bors) / 2) + map->move_horiz;
		map->points[*co].y = i * map->bors + ((map->size_y - map->max_y * map->bors) / 2) + map->move_vert;
		map->points[*co].color = map->color[*co];
		(*co)++;
	}
}

void			ft_fiil_in_point2(t_map *map, int i_int, int *counter)
{
	int i;
	int j;
	int temp_x;
	int temp_y;

	i = i_int;
	j = -1;
	temp_y = i;
	while (++j < map->max_x)
	{
		temp_x = j;
		map->points[*counter].z = map->matrix[i][j];
		map->points[*counter].x = (j - i) * cos(0.46373398) * map->bors + (map->size_x - map->max_x * map->bors) / 2 + map->move_horiz;
		map->points[*counter].y = (-map->matrix[temp_y][temp_x] + (j + i) * sin(0.46373398)) * map->bors + (map->size_y - map->max_y * map->bors) / 2 + map->move_vert;
		map->points[*counter].color = map->color[*counter];
		(*counter)++;
	}
	ft_printf("counter = %d\n", *counter);
}

void		ft_print_picture(t_map *map, int i, int j, int counter)
{
	while(++i < map->max_y)
	{
		j = -1;
		counter++;
		while (++j < map->max_x - 1)
		{
			draw_line(map, map->points[counter], map->points[counter + 1]);
			counter++;
		}
	}
	i = -1;
	while(++i < map->max_y - 1)
	{
		j = -1;
		counter = i * map->max_x;
		while (++j < map->max_x)
		{
			draw_line(map, map->points[counter], map->points[counter + map->max_x]);
			counter++;
		}
	}
}

void		ft_solution(t_map *map)
{
	t_boarder	bor;
	int			counter;
	int			i;
	int			j;

	i = -1;
	j = -1;
	counter = 0;
	ft_init_and_print_board(&bor, map);
	while (++i < map->max_y)
	{
		if (map->flag2d == 1 && map->flag3d == 0)
			ft_fiil_in_point(map, i, &counter);
		else if (map->flag2d == 0 && map->flag3d == 1)
			ft_fiil_in_point2(map, i, &counter);
	}
	if (map->z_rotation == 1)
		ud_rotation(map);
	counter = -1;
	i = -1;
	ft_print_picture(map, i, j, counter);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

void	ud_rotation(t_map *map)
{
	double	y0;

	int		num;

	num = -1;
	// if (key == kVK_ANSI_W)
	// 	map->sico = -0.1;
	while(++num < map->mul_xy)
	{
		y0 = (float)(map->points[num].y - (map->size_y - map->max_y) / 2);
		map->points[num].y = (int)((map->size_y - map->max_y) / 2 + y0 * cos(map->sico) + map->points[num].z * sin(map->sico));
		map->points[num].z = (int)(-y0 * sin(map->sico) + map->points[num].z * cos(map->sico));
	}
	ft_printf("Beach\n");
	//map->sico = 0.1;
	map->z_rotation = 0;
	// print(fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:25 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 22:01:41 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fill_in_points(t_map *map, int i_int, int *co)
{
	int j;

	j = -1;
	while (++j < map->max_x)
	{
		map->points[*co].z = (map->matrix[i_int][j]) * (map->bors + map->pull_z);
		map->points[*co].x = j * map->bors - map->max_x * map->bors / 2;
		map->points[*co].y = i_int * map->bors - map->max_y * map->bors / 2;
		map->points[*co].color = map->color[*co];
		x_rotation(map, map->points[*co].y, co);
		y_rotation(map, map->points[*co].x, co);
		z_rotation(map, map->points[*co].x, map->points[*co].y, co);
		if (map->iso == 1)
			ft_isometric_proj(map, co);
		map->points[*co].x += (WIDTH_OF_IMAGE) / 2 + map->move_horiz;
		map->points[*co].y += (HIGH_OF_IMAGE + map->max_y * map->bors)
			/ 2 + map->move_vert;
		(*co)++;
	}
}

void	ft_print_picture(t_map *map, int i, int j, int counter)
{
	while (++i < map->max_y)
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
	while (++i < map->max_y - 1)
	{
		j = -1;
		counter = i * map->max_x;
		while (++j < map->max_x)
		{
			draw_line(map, map->points[counter],
				map->points[counter + map->max_x]);
			counter++;
		}
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

void	ft_solution(t_map *map)
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
		ft_fill_in_points(map, i, &counter);
	map->start_pos = 0;
	counter = -1;
	i = -1;
	ft_print_picture(map, i, j, counter);
}

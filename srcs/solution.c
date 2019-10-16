/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:25 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/16 13:58:09 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_fiil_in_point(t_map *map, int i_int, int *counter)
{
	double i;
	double j;
	int temp_x;
	int temp_y;

	i = i_int;
	j = -1;
	temp_y = i;
	while (++j < map->max_x)
	{
		temp_x = j;
		map->points[*counter].z = map->matrix[temp_y][temp_x];
		map->points[*counter].x = (int)(((j - i) * cos(0.46373398)) + map->size_x / 2 + map->move_vert);
		map->points[*counter].y = (int)((-map->matrix[temp_y][temp_x] + (j + i) * sin(0.46373398)) + map->size_y / 2 + map->move_horiz);
		(*counter)++;
	}
}

void		ft_solution(t_map *map)
{
	int		counter;
	int		i;
	int		j;

	i = -1;
	counter = 0;
	//ft_bzero(map->img_data, map->size_x * map->size_y);
	while (++i < map->max_y)
		ft_fiil_in_point(map, i, &counter);
	i = -1;
	counter = -1;
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
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

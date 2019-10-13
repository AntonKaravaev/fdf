/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:25 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/13 23:36:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fiil_in_point(t_map *map, int i_int, int *counter)
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
		// j = (temp_x - temp_y) * cos(0.46373398);
		// i =  + (temp_x + temp_y) * sin(0.46373398);

		map->points[*counter].z = map->matrix[temp_y][temp_x];
		map->points[*counter].x = (int)((((j - i) * cos(0.46373398)) * 30 + (map->size_x / 2 / map->max_x) + map->size_x / 2 - map->size_x / 4));
		map->points[*counter].y = (int)(((-map->matrix[temp_y][temp_x] + (j + i) * sin(0.46373398)) * 10 + (map->size_y / 2 / map->max_y) + map->size_y / 2 - map->size_y / 4)) + 500;
		
		map->points[*counter].color = (int)0x0ef01d;
		(*counter)++;
	}
}

void	ft_solution(t_map *map)
{
	int		counter;
	int		i;
	int		j;

	i = -1;
	counter = 0;
	map->points = (t_point *)ft_memalloc(sizeof(t_point) * map->mul_xy);
	while (++i < map->max_y)
		ft_fiil_in_point(map, i, &counter);

ft_printf("map->max_x = %d\n", map->max_x);
ft_printf("map->max_y = %d\n", map->max_y);
	i = -1;
	j = -1;
	counter = -1;
	while(++i < map->max_y)
	{
		j = -1;
		counter++;
		ft_printf("counter = %d\n", counter);
		while (++j < map->max_x - 1)
		{

			ft_printf("counter  = %d, x = %d, y = %d\n", counter, map->points[counter].x,  map->points[counter].y);
			ft_printf("counter  = %d, x = %d, y = %d\n", counter + 1, map->points[counter + 1].x,  map->points[counter + 1].y);
			draw_line(map, map->points[counter], map->points[counter + 1]);
			counter++;
		}
	}

	i = -1;
	j = -1;
	while(++i < map->max_y - 1)
	{
		j = -1;
		counter = i * map->max_x;
		ft_printf("counter = %d\n", counter);
		while (++j < map->max_x)
		{

			ft_printf("counter  = %d, x = %d, y = %d\n", counter, map->points[counter].x,  map->points[counter].y);
			ft_printf("counter  = %d, x = %d, y = %d\n", counter, map->points[counter + map->max_x].x,  map->points[counter + map->max_x].y);
			draw_line(map, map->points[counter], map->points[counter + map->max_x]);
			counter++;
		}
	}


}



// void	ft_fiil_in_point(t_map *map, int i_int, int *counter)
// {
// 	double i;
// 	double j;
// 	int temp_x;
// 	int temp_y;

// 	i = i_int;
// 	j = -1;
// 	temp_y = i;
// 	while (++j < map->max_x)
// 	{
// 		temp_x = j;
// 		j = (temp_x - temp_y) * cos(0.46373398);
// 		i = -map->matrix[temp_y][temp_x] + (temp_x + temp_y) * sin(0.46373398);
// 		map->points[*counter].x = ((j * (map->size_x / 2 / map->max_x) + map->size_x / 2 - map->size_x / 4) - (i * (map->size_y / 2 / map->max_y) + map->size_y / 2 - map->size_y / 4))   * cos(0.46373398);
// 		map->points[*counter].y = i * (map->size_y / 2 / map->max_y) + map->size_y / 2 - map->size_y / 4;
// 		map->points[*counter].z = map->matrix[temp_y][temp_x];
// 		map->points[*counter].color = (int)0x0ef01d;
// 		(*counter)++;
// 	}
// }
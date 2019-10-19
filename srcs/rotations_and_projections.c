/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_and_projections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:22:59 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 20:41:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_rotation(t_map *map, int pr_y, int *co)
{
	map->points[*co].y = cos(map->alfa)
		* pr_y + sin(map->alfa) * map->points[*co].z;
	map->points[*co].z = sin(map->alfa)
		* (-pr_y) + cos(map->alfa) * map->points[*co].z;
}

void	y_rotation(t_map *map, int pr_x, int *co)
{
	map->points[*co].x = cos(map->beta)
		* pr_x + sin(map->beta) * map->points[*co].z;
	map->points[*co].z = sin(map->beta)
		* (-pr_x) + cos(map->beta) * map->points[*co].z;
}

void	z_rotation(t_map *map, int pr_x, int pr_y, int *co)
{
	map->points[*co].x = cos(map->gamma)
		* pr_x - sin(map->gamma) * pr_y;
	map->points[*co].y = sin(map->gamma)
		* pr_x + cos(map->gamma) * pr_y;
}

void	ft_isometric_proj(t_map *map, int *counter)
{
	int temp_x;
	int temp_y;

	temp_x = map->points[*counter].x;
	temp_y = map->points[*counter].y;
	map->points[*counter].x = (temp_x - temp_y) * cos(0.523599);
	map->points[*counter].y = -map->points[*counter].z
		+ (temp_x + temp_y) * sin(0.523599);
}

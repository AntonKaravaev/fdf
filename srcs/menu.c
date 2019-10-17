/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:33:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/18 01:20:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_map *map)
{
	int		i;

	i = 0;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1250, i += 20, color_of_board, "Menu");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 35, color_of_board, "Zoom: Put the button +/-");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 30, color_of_board, "Move: Arrows");
	// mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 30, color_of_board, "Flatten: </>");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 30, color_of_board, "Rotate:");
//	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 25, color_of_board, "X-Axis - 2/8");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 25, color_of_board, "Y-Axis - w/s");
//	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 25, color_of_board, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1223, i += 30, color_of_board, "Projection");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 25, color_of_board, "ISO: Put the button 2, 4");
	mlx_string_put(map->mlx_ptr, map->win_ptr,  1100, i += 25, color_of_board, "Parallel: Put the button 1, 3");
}
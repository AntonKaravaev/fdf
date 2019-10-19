/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:33:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 23:07:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_map *map)
{
	int		i;
	void	*m;
	void	*w;

	i = 0;
	m = map->mlx_ptr;
	w = map->win_ptr;
	mlx_string_put(m, w, 1250, i += 20, COB, "Menu");
	mlx_string_put(m, w, 1100, i += 35, COB, "Zoom: Put the button +/-");
	mlx_string_put(m, w, 1100, i += 30, COB, "Move: Arrows");
	mlx_string_put(m, w, 1100, i += 30, COB, "Pull_the_hight: P/O");
	mlx_string_put(m, w, 1100, i += 30, COB, "Rotate:");
	mlx_string_put(m, w, 1100, i += 25, COB, "X-Axis - W/S");
	mlx_string_put(m, w, 1100, i += 25, COB, "Y-Axis - A/D");
	mlx_string_put(m, w, 1100, i += 25, COB, "Z-Axis - Q/Z");
	mlx_string_put(m, w, 1223, i += 30, COB, "Projection");
	mlx_string_put(m, w, 1100, i += 25, COB, "ISO: Put the button 2, 4");
	mlx_string_put(m, w, 1100, i += 25, COB, "Parallel: Put the button 1, 3");
}

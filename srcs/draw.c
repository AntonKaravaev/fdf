/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:39:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/17 16:27:03 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_map *map, int x, int y, int color)
{
	int		i;

	i = (x) + (y * map->size_x); //map->max_x
	map->img_data[i] = color;
}

void    draw_line(t_map *map, t_point s, t_point f)
{
	t_point i_am;
	int		dx;
	int		dy;
	int		err[2];
	int		sign_dx;
	int		sign_dy;

	dx = abs(f.x - s.x); // absolute value // can I use it?
	dy = abs(f.y - s.y);
	sign_dx = s.x < f.x ? 1 : -1;
	sign_dy = s.y < f.y ? 1 : -1;
	err[0] = dx - dy;
	put_pixel(map, s.x, s.y, s.color); // ?
	i_am  = s;
	while(i_am.x != f.x || i_am.y != f.y)
	{
		put_pixel(map, i_am.x, i_am.y, s.color);
		if ((err[1] = 2 * err[0]) > -dy)
		{
			err[0]= err[0] - dy;
			i_am.x = i_am.x + sign_dx;
		}
		if (err[1] < dx)
		{
			err[0] = err[0] + dx;
			i_am.y = i_am.y + sign_dy;
		}
	}
	put_pixel(map, i_am.x, i_am.y, s.color);
}

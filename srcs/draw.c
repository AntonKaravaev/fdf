/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:39:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 20:45:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_map *map, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH_OF_IMAGE && y >= 0 && y < HIGH_OF_IMAGE)
	{
		i = (x) + (y * map->size_x);
		map->img_data[i] = color;
	}
}

void		draw_line(t_map *map, t_point s, t_point f)
{
	t_point i_am;
	t_draw	draw;

	draw.dx = abs(f.x - s.x);
	draw.dy = abs(f.y - s.y);
	draw.sign_dx = s.x < f.x ? 1 : -1;
	draw.sign_dy = s.y < f.y ? 1 : -1;
	draw.err[0] = draw.dx - draw.dy;
	i_am = s;
	put_pixel(map, i_am.x, i_am.y, s.color);
	while (i_am.x != f.x || i_am.y != f.y)
	{
		put_pixel(map, i_am.x, i_am.y, s.color);
		if ((draw.err[1] = 2 * draw.err[0]) > -draw.dy)
		{
			draw.err[0] = draw.err[0] - draw.dy;
			i_am.x = i_am.x + draw.sign_dx;
		}
		if (draw.err[1] < draw.dx)
		{
			draw.err[0] = draw.err[0] + draw.dx;
			i_am.y = i_am.y + draw.sign_dy;
		}
	}
	put_pixel(map, i_am.x, i_am.y, s.color);
}

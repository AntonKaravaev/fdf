/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:39:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/13 22:57:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int			sgn(int x)
// {
// 	if (x > 0)
// 		return (1);
// 	if (x < 0)
// 			return (-1);
// 	else
// 		return (0);
// }

// char		*draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y)
// {
// 	int		dx;
// 	int		dy;
// 	int		error;
// 	int		sign_dx;
// 	int		sign_dy;
// 	char	*img;

// 	img = ft_memalloc(size_x * size_y * 4 * 4);
// 	dx = abs(x0 - x1);
// 	dy = abs(y0 - y1);
// 	sign_dx = x0 < x1 ? 1 : -1;
// 	sign_dy = y0 < y1 ? 1 : -1;
// 	error = dx - dy;
// 	img[(x1) * 4  + (y1) * size_x * 4] = (char)255; //-??
// 	while(x0 != x1 || y0 != y1)
// 	{
// 		img[x0 * 4  + y0 * size_x * 4] = (char)255;
// 		if (2 * error > -dy)
// 		{
// 			error = error - dy;
// 			x0 = x0 + sign_dx;
// 		}
// 		if (2 * error < dx)
// 		{
// 			error = error + dx;
// 			y0 = y0 + sign_dy;
// 		}
// 	}
// 	return (img);
// }


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
}

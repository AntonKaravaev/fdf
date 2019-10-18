/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:36:45 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/18 16:03:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iapb(t_boarder *bor)
{
	bor->p[0].x = 0;
	bor->p[0].y = 0;
	bor->p[0].z = 0;
	bor->p[0].color = color_of_board;
	bor->p[1].x = 999;
	bor->p[1].y = 0;
	bor->p[1].z = 0;
	bor->p[1].color = color_of_board;
	bor->p[2].x = 0;
	bor->p[2].y = 999;
	bor->p[2].z = 0;
	bor->p[2].color = color_of_board;
	bor->p[3].x = 999;
	bor->p[3].y = 999;
	bor->p[3].z = 0;
	bor->p[3].color = color_of_board;
}

void	ft_init_and_print_board(t_boarder *bor, t_map *map)
{
	t_point s;
	t_point f;

	ft_iapb(bor);
	s = bor->p[0];
	f = bor->p[1];
	draw_line(map, s, f);
	s = bor->p[0];
	f = bor->p[2];
	draw_line(map, s, f);
	s = bor->p[2];
	f = bor->p[3];
	draw_line(map, s, f);
	s = bor->p[1];
	f = bor->p[3];
	draw_line(map, s, f);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:21:22 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/20 13:41:26 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		key_press_sup1(int keycode, t_map *map)
{
	if (keycode == KVK_ANSI_1)
	{
		map->iso = 0;
		map->move_vert = 0;
		map->move_horiz = 0;
		map->pull_z = 0;
		map->alfa = 0.0;
		map->beta = 0.0;
		map->gamma = 0.0;
		ft_find_the_right_bors(&map->bors, &map->mul_xy);
		return (1);
	}
	else if (keycode == KVK_ANSI_2)
	{
		map->iso = 1;
		map->move_vert = 0;
		map->move_horiz = 0;
		map->pull_z = 0;
		map->alfa = 0.0;
		map->beta = 0.0;
		map->gamma = 0.0;
		ft_find_the_right_bors(&map->bors, &map->mul_xy);
		return (1);
	}
	return (0);
}

static int		key_press_sup2(int k, t_map *map)
{
	if (k == KVK_ANSI_3)
	{
		map->alfa = 0.0;
		map->beta = 0.0;
		map->gamma = 0.0;
		map->iso = 0;
	}
	else if (k == KVK_ANSI_4)
		map->iso = 1;
	else if (k == KVK_UP_ARROW)
		map->move_vert += 10;
	else if (k == KVK_DOWN_ARROW)
		map->move_vert -= 10;
	else if (k == KVK_LEFT_ARROW)
		map->move_horiz -= 10;
	else if (k == KVK_RIGHT_ARROW)
		map->move_horiz += 10;
	if (k == KVK_ANSI_3 || k == KVK_ANSI_4 || k == KVK_UP_ARROW
		|| k == KVK_DOWN_ARROW || k == KVK_LEFT_ARROW || k == KVK_RIGHT_ARROW)
		return (1);
	return (0);
}

static int		key_press_sup3(int k, t_map *map)
{
	if (k == VK_ANSI_PLUS)
	{
		if (map->bors <= 100)
			map->bors += 1;
	}
	else if (k == KVK_ANSI_MINUS)
	{
		if (map->bors >= 2)
			map->bors -= 1;
	}
	else if (k == KVK_ANSI_P)
		map->pull_z += 1;
	else if (k == KVK_ANSI_O)
		map->pull_z -= 1;
	else if (k == KVK_ANSI_W)
		map->alfa += -0.1;
	if (k == VK_ANSI_PLUS || k == KVK_ANSI_MINUS || k == KVK_ANSI_P
		|| k == KVK_ANSI_O || k == KVK_ANSI_W)
		return (1);
	return (0);
}

static int		key_press_sup4(int k, t_map *map)
{
	if (k == KVK_ANSI_S)
		map->alfa += 0.1;
	else if (k == KVK_ANSI_A)
		map->beta += -0.1;
	else if (k == KVK_ANSI_D)
		map->beta += 0.1;
	else if (k == KVK_ANSI_Q)
		map->gamma += -0.1;
	else if (k == KVK_ANSI_Z)
		map->gamma += 0.1;
	if (k == KVK_ANSI_S || k == KVK_ANSI_A || k == KVK_ANSI_D
		|| k == KVK_ANSI_Q || k == KVK_ANSI_Z)
		return (1);
	return (0);
}

int				key_press(int keycode, t_map *map)
{
	ft_bzero(map->img_data, map->size_x * map->size_y * 4);
	if (keycode == KVK_ESCAPE)
		exit(0);
	if (key_press_sup1(keycode, map) == 1)
		;
	if (key_press_sup2(keycode, map) == 1)
		;
	if (key_press_sup3(keycode, map) == 1)
		;
	if (key_press_sup4(keycode, map) == 1)
		;
	ft_solution(map);
	return (0);
}

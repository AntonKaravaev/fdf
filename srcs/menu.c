/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:33:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/20 13:24:08 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_menu_sup(t_map *map, int *i, void *m, void *w)
{
	char	*str;
	char	*itoa_str;

	itoa_str = ft_itoa(map->move_vert);
	str = ft_strjoin("move_vert = \0", itoa_str);
	mlx_string_put(m, w, 1100, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
	itoa_str = ft_itoa(map->move_horiz);
	str = ft_strjoin("move_horiz = ", itoa_str);
	mlx_string_put(m, w, 1100, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
	itoa_str = ft_itoa(map->pull_z);
	str = ft_strjoin("pull_hight = ", itoa_str);
	mlx_string_put(m, w, 1100, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
	itoa_str = ft_itoa(map->bors);
	str = ft_strjoin("zoom = ", itoa_str);
	mlx_string_put(m, w, 1100, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
}

void		print_menu(t_map *map)
{
	int		i;
	void	*m;
	void	*w;

	i = 0;
	m = map->mlx_ptr;
	w = map->win_ptr;
	mlx_clear_window(m, w);
	mlx_string_put(m, w, 1250, i += 65, COB, "MENU");
	mlx_string_put(m, w, 1100, i += 30, COB, "Zoom: Put the button +/-");
	mlx_string_put(m, w, 1100, i += 30, COB, "Move: Arrows");
	mlx_string_put(m, w, 1100, i += 30, COB, "Pull_the_hight: P/O");
	mlx_string_put(m, w, 1240, i += 65, COB, "Rotate");
	mlx_string_put(m, w, 1100, i += 30, COB, "X-Axis - W/S");
	mlx_string_put(m, w, 1100, i += 30, COB, "Y-Axis - A/D");
	mlx_string_put(m, w, 1100, i += 30, COB, "Z-Axis - Q/Z");
	mlx_string_put(m, w, 1223, i += 65, COB, "Projection");
	mlx_string_put(m, w, 1100, i += 30, COB, "ISO: Put the button 2, 4");
	mlx_string_put(m, w, 1100, i += 30, COB, "Parallel: Put the button 1, 3");
	print_menu_sup(map, &i, m, w);
}

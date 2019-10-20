/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/20 13:27:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_matrix(int **matrix, int max_y, int max_x)
{
	int i;
	int j;

	i = -1;
	while (++i < max_y)
	{
		j = -1;
		while (++j < max_x)
			printf("%3d", matrix[i][j]);
		printf("\n");
	}
}

static int	**creat_matrix(t_list **alst, int max_y)
{
	int		**matrix;
	t_list	*tmp;

	tmp = *alst;
	if (!(matrix = (int**)malloc(sizeof(int*) * (max_y))))
		exit(-1);
	max_y--;
	while (max_y >= 0)
	{
		matrix[max_y] = tmp->content;
		tmp = tmp->next;
		max_y--;
	}
	tmp = NULL;
	return (matrix);
}

static void	take_int_sup_color(t_map *map)
{
	if (map->temp_color != 0)
	{
		map->color[map->po] = map->temp_color;
		map->temp_color = 0;
	}
	else
		map->color[map->po] = (int)(0x0ef01d);
}

int			*take_int(t_map *map, char *line, int *max_x)
{
	char	**split;
	int		*array;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	ft_strdel(&line);
	while (split[i])
		i++;
	array = (int*)ft_memalloc(i * 4);
	*max_x = i;
	i = -1;
	while (++i < *max_x)
	{
		++map->po;
		array[i] = ft_tricky_atoi(map, split[i]);
		take_int_sup_color(map);
	}
	ft_str2del(&split);
	return (array);
}

int			read_file(t_map *map, int fd)
{
	t_list	*start;
	char	*line;
	int		tmp;

	start = NULL;
	if (get_next_line(fd, &line) == 1)
		ft_lstadd(&start, ft_lstnew(take_int(map, line, &map->max_x),
			(map->max_x) * sizeof(int)));
	map->max_y++;
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd(&start, ft_lstnew(take_int(map, line, &tmp),
			(map->max_x) * sizeof(int)));
		if (tmp != map->max_x)
		{
			ft_putstr_fd("Error. Not the same width in lines.", 2);
			exit(-1);
		}
		map->max_y++;
	}
	map->matrix = creat_matrix(&start, map->max_y);
	print_matrix(map->matrix, map->max_y, map->max_x);
	map->mul_xy = map->max_x * map->max_y;
	return (1);
}

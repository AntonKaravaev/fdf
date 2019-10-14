/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/14 22:29:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_matrix(int **matrix, int max_y, int max_x)
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

int			**creat_matrix(t_list **alst, int max_y)
{
	int		**matrix;
	t_list	*tmp;

	tmp = *alst;
	if (!(matrix = (int**)malloc(sizeof(int*) * (max_y))))
		exit(-1);
	while (max_y >= 0)
	{
		matrix[max_y] = tmp->content;
		tmp = tmp->next;
		max_y--;
	}
    tmp = NULL;
	return (matrix);
}

int			*take_int(t_map *map, char *line, int *max_x)
{
		char    **split;
		int     *array;
		int     i;

		i = 0;
		split = ft_strsplit(line, ' ');
        //ft_strdel(&line);
		while (split[i])
			i++;
		array = (int*)ft_memalloc(i * 4);
		*max_x = i;
		i = -1;
		while (++i < *max_x)
		{
			array[i] = ft_tricky_atoi(map, split[i]);
			if (map->max_z < abs(array[i]))
				map->max_z = abs(array[i]);
		}
        //ft_str2del(&split);
		ft_printf("map->max_z = %d\n", map->max_z);
		return (array);
}

int			read_file(t_map *map, int fd)
{
    t_list	*start;
	char	*line;
	int		tmp;

	start = NULL;
	map->max_y = 0;
	map->max_x = 0;
	if (get_next_line(fd, &line) == 1)
			ft_lstadd(&start, ft_lstnew(take_int(map, line, &map->max_x), (map->max_x) * sizeof(int)));
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd(&start, ft_lstnew(take_int(map, line, &tmp), (map->max_x) * sizeof(int)));
		if (tmp != map->max_x)
        {
            ft_putstr_fd("Error. Not the same width in lines.", 2);
			exit(-1);
        }
		map->max_y++;
	}
	map->matrix = creat_matrix(&start, map->max_y);
	//ft_lstdel(start); // Зафришить список!!!
	print_matrix(map->matrix, map->max_y, map->max_x);
    map->mul_xy = map->max_x * map->max_y;
	return (1);
}

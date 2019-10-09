/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:44:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/09 18:38:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			sgn(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
			return (-1);
	else
		return (0);
}

char		*draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y)
{
	int		dx;
	int		dy;
	int		error;
	int		sign_dx;
	int		sign_dy;
	char	*img;

	img = ft_memalloc(size_x * size_y * 4 * 4);
	dx = abs(x0 - x1);
	dy = abs(y0 - y1);
	sign_dx = x0 < x1 ? 1 : -1;
	sign_dy = y0 < y1 ? 1 : -1;
	error = dx - dy;
	img[(x1) * 4  + (y1) * size_x * 4] = (char)255; //-??
	while(x0 != x1 || y0 != y1)
	{
		img[x0 * 4  + y0 * size_x * 4] = (char)255;
		if (2 * error > -dy)
		{
			error = error - dy;
			x0 = x0 + sign_dx;
		}
		if (2 * error < dx)
		{
			error = error + dx;
			y0 = y0 + sign_dy;
		}
	}
	return (img);
}

void		print_matrix(int **matrix, int max_y, int max_x)
{
	int i;
	int j;

	i = -1;
	while (++i < max_y)
	{
		j = -1;
		{
			while (++j < max_x)
				printf("%3d", matrix[i][j]);
			printf("\n");
		}
	}
}

int			**creat_matrix(t_list **alst, int max_y)
{
	int		**matrix;
	t_list	*tmp;

	tmp = *alst;
	matrix = (int**)malloc(sizeof(int*) * (max_y));
	while (max_y >= 0)
	{
		matrix[max_y] = tmp->content;
		tmp =  tmp->next ;
		max_y--;
	}
	//ftree lst(start)
	return (matrix);
}

//ВСЕ ФРИШИТЬ
int			*take_int(char *line, int *max_x)
{
		char **split;
		int *array;
		int i;

		i = 0;
		split = ft_strsplit(line, ' ');//проверка ВАЛИДНОСТИ?
		while (split[i])
			i++;
		array = (int*)ft_memalloc(i * 4);
		*max_x = i;
		i = -1;
		while (++i < *max_x)
			array[i] = ft_atoi(split[i]);//проверка что число?
		return (array);
}

int			read_file(int fd)
{
	char	*line;
	t_list	*start;
	int		max_y;
	int		max_x;
	int		tmp;
	int		**matrix;

	start = NULL;
	max_y = 0;
	max_x = 0;
	if (get_next_line(fd, &line) == 1)
			ft_lstadd(&start, ft_lstnew(take_int(line, &max_x), (max_x) * sizeof(int)));
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd(&start, ft_lstnew(take_int(line, &tmp), (max_x) * sizeof(int)));
		if (tmp != max_x)
			return (0);
		max_y++;
	}
	matrix = creat_matrix(&start, max_y);
	print_matrix(matrix, max_y, max_x);
	return (1);
}

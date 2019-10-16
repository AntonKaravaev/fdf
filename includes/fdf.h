/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:28:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/15 23:20:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
// # include <stdio.h>
# include <math.h>
// # include <strings.h>
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <stddef.h>
# define kVK_Escape	0x35
# define kVK_ANSI_W	0x0D
# define kVK_ANSI_S	0x01
# define kVK_ANSI_A 0x00
# define kVK_ANSI_D 0x02

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_map
{
	t_point	points[500000]; // ??
	int		po;
	int		*str; // ??
	void	*mlx_ptr;
	void	*win_ptr;
	int     *img_data;
	int		*img_ptr;
	int		bpp; // bits_per_pixel
	int		sl; // size line
	int		endian;
	int		**matrix;
	int		temp_color; 
	int		max_y; 
	int		max_x;
	int		mul_xy; // max_y * max_x;
	int		size_x;
	int		size_y;
	int		move_vert;
	int		move_horiz;
}				t_map;

int		read_file(t_map *map, int fd);
void	ft_solution(t_map *map);
// int		*take_int(char *line, int *max_x);
// int		**creat_matrix(t_list **alst, int max_y);
// void	print_matrix(int **matrix, int max_y, int max_x);
void	draw_line(t_map *map, t_point s, t_point f);
int		ft_tricky_atoi(t_map *map, const char *s);
int		key_press(int keycode, t_map *map);
// int		sgn(int x);
#endif

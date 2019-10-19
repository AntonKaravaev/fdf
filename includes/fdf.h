/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:28:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 23:53:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>

# define KVK_ESCAPE	0x35
# define KVK_ANSI_W	0x0D
# define KVK_ANSI_S	0x01
# define KVK_ANSI_A 0x00
# define KVK_ANSI_D 0x02
# define KVK_ANSI_Q 0x0C
# define KVK_ANSI_O 0x1F
# define KVK_ANSI_Z 0x06
# define KVK_ANSI_P 0x23
# define KVK_ANSI_1 0x12
# define KVK_ANSI_2 0x13
# define KVK_ANSI_3 0x14
# define KVK_ANSI_4 0x15
# define KVK_LEFT_ARROW 0x7B
# define KVK_RIGHT_ARROW 0x7C
# define KVK_DOWN_ARROW 0x7D
# define KVK_UP_ARROW 0x7E
# define VK_ANSI_PLUS 0x45
# define KVK_ANSI_MINUS 0x4E
# define COB 16763904
# define WIDTH_OF_WINDOW 1500
# define HIGH_OF_WINDOW 1000
# define WIDTH_OF_IMAGE 1000
# define HIGH_OF_IMAGE 1000

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		err[2];
	int		sign_dx;
	int		sign_dy;
}				t_draw;

typedef struct	s_map
{
	t_point	points[300000];
	int		color[300000];
	int		**matrix;
	int		po;
	int		*str;
	void	*mlx_ptr;
	void	*win_ptr;
	int     *img_data;
	int		*img_ptr;
	int		bpp;
	int		sl;
	int		endian;
	int		temp_color;
	int		max_y;
	int		max_x;
	int		mul_xy;
	int		size_x;
	int		size_y;
	int		move_vert;
	int		move_horiz;
	int		pull_z;
	int		iso;
	int		bors;
	float	alfa;
	float	beta;
	float	gamma;
	int		start_pos;
}				t_map;

typedef struct	s_boarder
{
	t_point p[4];
}				t_boarder;

int		read_file(t_map *map, int fd);
void	ft_init_and_print_board(t_boarder *bor, t_map *map);
int		ft_tricky_atoi(t_map *map, const char *s);
void	ft_atoisup(long n, int s, char c);
void	ft_atoizero(char *s);
int		ft_atoi_base(const char *str, int base);
void	ft_error_atoi();
void	ft_solution(t_map *map);
void	ft_fill_in_points(t_map *map, int i_int, int *co);
void	x_rotation(t_map *map, int pr_y, int *co);
void	y_rotation(t_map *map, int pr_x, int *co);
void	z_rotation(t_map *map, int pr_x, int pr_y, int *co);
void	ft_isometric_proj(t_map *map, int *counter);
void	draw_line(t_map *map, t_point s, t_point f);
int		key_press(int keycode, t_map *map);
void	ft_isometric_proj(t_map *map, int *counter);
void	print_menu(t_map *map);
int		key_press(int keycode, t_map *map);
void	ft_find_the_right_bors(int *bors, int *mul);

#endif

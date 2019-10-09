/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:28:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/09 18:36:37 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <math.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct  s_point
{
  int x;
  int y;
  int z;
  int color;
} t_point;

int		read_file(int fd);
int		*take_int(char *line, int *max_x);
int		**creat_matrix(t_list **alst, int max_y);
void	print_matrix(int **matrix, int max_y, int max_x);
char	*draw_line(int x0, int x1, int y0, int y1, int size_x, int size_y);
int		sgn(int x);

#endif

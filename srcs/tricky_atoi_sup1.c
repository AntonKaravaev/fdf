/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricky_atoi_sup1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:47:07 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/19 20:52:58 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nbr;

	i = 2;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		i += 1;
	}
	return (nbr);
}

void		ft_atoizero(char *s)
{
	if ((s[1] != '\0') && (s[0] == '0'))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if ((s[1] == '\0') && (s[0] == '-'))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

void		ft_atoisup(long n, int s, char c)
{
	if (n > 2147483647 || n * s < -2147483648 || (c - '0' < 0 || c - '0' > 9))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

void		ft_error_atoi(void)
{
	ft_putstr_fd("Error. Not a good color of the pixel.", 2);
	exit(-1);
}

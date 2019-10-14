/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricky_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:28:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/14 22:37:29 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_atoizero(char *s)
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

static void		ft_atoisup(long n, int s, char c)
{
	if (n > 2147483647 || n * s < -2147483648 || (c - '0' < 0 || c - '0' > 9))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

static int	ft_tricky_atoi_sup2(const char *s)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	ft_atoizero((char *)s);
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		ft_atoisup(n, sign, s[i]);
		i++;
	}
	if (s[i] != '\0')
		ft_atoisup(n, sign, s[i]);
	return ((int)(n * sign));
}

int				ft_tricky_atoi(t_map *map, const char *s)
{
    (void)map;
	if (ft_strstr(s, ",") == NULL)
        return(ft_tricky_atoi_sup2(s));
    return(1);
}
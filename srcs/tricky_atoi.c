/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricky_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:28:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/17 13:43:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int		ft_atoi_base(const char *str, int base)
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

static int		ft_tricky_atoi_sup2(const char *s)
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

static void		ft_tas3_sup(t_map *map, char ***s)
{
	int i;

	i = 0;
	while ((*s)[1][i] != '\0')
		i++;
	if (i != 8 || (*s)[1][0] != '0' || (*s)[1][1] != 'x')
	{
		ft_putstr_fd("Error. Not a good color of the pixel.", 2);
		exit(-1);
	}
	else
	{
		i = 2;
		while (i < 8)
		{
			if (((*s)[1][i] >= '0' && (*s)[1][i] <= '9') || ((*s)[1][i] >= 'A' && (*s)[1][i] <= 'F') || ((*s)[1][i] >= 'a' && (*s)[1][i] <= 'f'))
				i++;
			else
			{
				ft_putstr_fd("Error. Not a good color of the pixel.", 2);
				exit(-1);
			}
		}
		map->temp_color = ft_atoi_base((*s)[1], 16);
	}	
}

static int		ft_tricky_atoi_sup3(t_map *map, const char *s)
{
	char	**str;
	int		number;

	str = ft_strsplit(s, ',');
	if (str[0] != NULL && str[1] != NULL && str[2] == NULL)
	{
		number = ft_tricky_atoi_sup2(str[0]);
		ft_tas3_sup(map, &str);
		return (number);
	}
	else
	{
		ft_putstr_fd("Error. Not a good high or color of the pixel.", 2);
		exit(-1);
	}
	return (0);
}

int				ft_tricky_atoi(t_map *map, const char *s)
{
	if (ft_strstr(s, ",") == NULL)
		return(ft_tricky_atoi_sup2(s));
	else
		return(ft_tricky_atoi_sup3(map, s));
	return(1);
}

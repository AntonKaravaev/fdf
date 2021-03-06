/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:39:30 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/28 14:11:43 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_ch(int n, int length)
{
	int ch;

	ch = n;
	while (length != 1)
	{
		ch = ch / 10;
		length--;
	}
	return (ch % 10);
}

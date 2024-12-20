/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:38:06 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/09/30 14:35:49 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\t') || (c == '\r')
		|| (c == '\n') || (c == '\v') || (c == '\f'));
}

long	ft_atol(const char *str)
{
	long		num;
	long		buffer;
	int			sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		buffer = num;
		num = num * 10 + (*str - '0');
		if (num / 10 != buffer && sign == -1)
			return (0);
		else if (num / 10 != buffer && sign == 1)
			return (-1);
		str++;
	}
	return (num * sign);
}

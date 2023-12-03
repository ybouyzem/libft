/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:50:22 by ybouyzem          #+#    #+#             */
/*   Updated: 2023/11/12 12:51:01 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}

static int	ft_getdigit(const char *str, int *i, int *sign)
{
	long int	r;
	long int	tmp;

	tmp = 0;
	r = 0;
	while (ft_isdigit(str[*i]) && str[*i])
	{
		r = (str[*i] - 48) + tmp * 10;
		if (tmp > r && *sign == 1)
			return (-1);
		if (tmp > r && *sign == -1)
			return (0);
		*i = *i + 1;
		tmp = r;
	}
	return (r * *sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	r;
	long int	tmp;

	tmp = 0;
	r = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_getdigit(str, &i, &sign));
}

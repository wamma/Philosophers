/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:10:16 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/05 20:31:50 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static const char	*ft_space(const char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else
			break ;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	str = ft_space(str);
	if (*str == '-' || *str == '+')
	{
		if (!ft_isdigit(*(str + 1)))
			ft_error();
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = result * sign;
	if (*str != '\0' || result > MAX_INT || result < MIN_INT)
		ft_error();
	return ((int)result);
}

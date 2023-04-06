/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:10:16 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/06 19:23:15 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
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
			ft_error("Argument Error");
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
	if (*str != '\0' || result > 2147483647 || result < -2147483648)
		ft_error("Argument Rage Error");
	return ((int)result);
}

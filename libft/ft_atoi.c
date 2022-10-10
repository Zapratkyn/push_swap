/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:35:38 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/05 17:08:16 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	return (0);
}

int	ft_end_of_number(char *str, int i)
{
	if (str[i] == ',')
	{
		i++;
		if (!str[i])
			return (0);
		while (str[i] == '0')
			i++;
		if (str[i])
			return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long long			result;
	int					i;
	int					sign;

	result = 0;
	sign = 1;
	for (i = 0; ft_is_space(str[i]); i++);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	for (i = i; str[i] == '0'; i++);
	if (str[i] < '1' || str[i] > '9')
			return (0);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result = result * sign;
	if (!ft_end_of_number(str, i) || result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int	ft_iszero(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] != ',' && str[i] != '\0')
		return (0);
	else if (str[i] == ',')
	{
		i++;
		if (!str[i])
			return (0);
		while (str[i] == '0')
			i++;
		if (str[i] != '\0')
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:25:33 by sohan             #+#    #+#             */
/*   Updated: 2021/04/08 03:54:53 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_atoi(char *str)
{
	int	result;
	int	n_power_of_ten;

	n_power_of_ten = 1;
	result = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || \
							*str == '\n' || *str == '\v' || \
							*str == '\f' || *str == '\r'))
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n_power_of_ten *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	str--;
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - 48) * n_power_of_ten;
		n_power_of_ten *= 10;
		str--;
	}
	return (result);
}

int main()
{
	printf("%d\n", ft_atoi("--\r2147483647\r"));
	return 0;
}

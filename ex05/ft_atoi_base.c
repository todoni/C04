/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:46:44 by sohan             #+#    #+#             */
/*   Updated: 2021/04/05 22:11:38 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_exception(char *base)
{
	int n;
	
	n = 0;
	while (*base != 0)
	{
		if (*base - *(base + 1) == 0 || *base == '+' || *base == '-')
			return (0);
		base++;
		n++;
	}
	if (n == 1)
		return (0);
	return (n);
}

int	find_base_index(char *base, char str)
{
	int index;

	index = 0;
	while (str != *base && *base != '\0')
	{
		base++;
		index++;
	}
	return (index);
}

int	calculate_result(char *str, char *base, int n_power_of_base)
{
	int index;
	int result;
	int n;

	index = 0;
	result = 0;
	n = is_exception(base);
	while (*str != '-' && *str != '+')
	{
		index = find_base_index(base, *str);
		result = result + index * n_power_of_base;
		n_power_of_base *= n;
		str--;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		n_power_of_base;
	
	n_power_of_base = 1;
	result = 0;
	if (is_exception(base) == 0)
		return (0);
	while (*str != '\0' && (*str < '!' || *str == '-' || *str == '+'))
	{
		if (*str == '-')
			n_power_of_base *= -1;
		str++;
	}
	while (*str != '\0')
		str++;
	str--;
	result = calculate_result(str, base, n_power_of_base);
	return (result);
}

int	main()
{
	printf("%d\n", ft_atoi_base("   ---+--+--2147483648","0123456789"));
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduced_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:25:33 by sohan             #+#    #+#             */
/*   Updated: 2021/04/05 17:52:26 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		count_minus(char *str)
{
	int minus;

	minus = 0;
	while (*str != '\0' && *str < '0')
	{
		if (*str == '-')
		{
			minus++;
		}
		str++;
	}
	return (minus);
}

char	*put_integer(char *str)
{
	char		*integer;
	static char	num[10];
	int			i;

	i = 0;
	while (i < 10)
	{
		num[i] = '\0';
		i++;
	}
	integer = num;
	i = 0;
	while (*str != '\0' && *str <= '9')
	{
		if (*str >= '0' && *str <= '9')
		{
			num[i] = *str;
			i++;
		}
		str++;
	}
	return (integer);
}

int		count_len(char *integer)
{
	int len;

	len = 0;
	while (*integer != '\0')
	{
		len++;
		integer++;
	}
	return (len);
}

int		create_integer(char *integer, int n_power_of_ten)
{
	int digit;
	int i;
	int result;

	i = count_len(integer);
	digit = 0;
	result = 0;
	while (i >= 1)
	{
		result = result + (integer[i - 1] - 48) * n_power_of_ten;
		if (digit < 10)
		{
			n_power_of_ten = n_power_of_ten * 10;
		}
		else
		{
			n_power_of_ten = n_power_of_ten * 1;
		}
		i--;
		digit++;
	}
	return (result);
}

int		ft_atoi(char *str)
{
	char	*integer;
	int		result;
	int		minus;
	int		n_power_of_ten;

	n_power_of_ten = 1;
	minus = count_minus(str);
	integer = put_integer(str);
	if (minus % 2 != 0)
	{
		n_power_of_ten = -n_power_of_ten;
	}
	result = create_integer(integer, n_power_of_ten);
	return (result);
}

int	main()
{
	printf("%d\n", ft_atoi("   ---+-+++-0asdf344"));
	printf("%d\n", ft_atoi("   --+-+++-01230asdf344"));
	printf("%d\n", ft_atoi("   ---+-+++-2147483648asdf344"));
	printf("%d\n", ft_atoi("   --+-+++-2147483647asdf344"));
	return 0;
}

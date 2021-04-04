/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:08:59 by sohan             #+#    #+#             */
/*   Updated: 2021/04/04 23:36:38 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int minus;
	int multiple;
	int i;
	int integer[10];
	int return_value;
	int check;

	minus = 0;
	multiple = 1;
	i = 0;
	check = 0;
	return_value = 0;
	while (*str != '\0')
	{
		if (*str == '-')
		{
			minus++;
		}
		while (*str >= '0' && *str <= '9' && *str != '\0')
		{
			integer[i] = *str - 48;
			if (multiple <= 100000000)
			{
				multiple = multiple * 10;
			}
			else
			{
				multiple = multiple * 1;
			}	
			str++;
			i++;
			check = 1;	
		}
		if (i != 10 && check != 0)
		{	
			multiple = multiple / 10;
		}
		if (minus % 2 != 0 && check != 0)
		{	
			multiple = -multiple;
		}
		i = 0;
		while(multiple != 1 && multiple != -1)
		{	return_value = return_value + integer[i] * multiple; 
			multiple = multiple / 10;
			i++;
		}
		if (check != 0)
		{
			return_value = return_value + integer[i] * multiple;
			return (return_value);
		}
		str++;
	}
	return (return_value);
}

int main()
{
	printf("%d",ft_atoi("  --+--+2147483648asdf345"));
	return 0;
}

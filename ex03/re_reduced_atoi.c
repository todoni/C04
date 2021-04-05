/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_reduced_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:25:33 by sohan             #+#    #+#             */
/*   Updated: 2021/04/05 19:07:11 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str)
{
	int		result;
	int		n_power_of_ten;
	
	n_power_of_ten = 1;
	result = 0;
	while (*str != '\0' && *str < '0')
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

int	main()
{
	printf("%d\n", ft_atoi("   ---+-+++-000"));
	printf("%d\n", ft_atoi("   --+-+++-01230344asdf456"));
	printf("%d\n", ft_atoi("   ---+-+++-2147483648asdf13"));
	printf("%d\n", ft_atoi("   --+-+++-2147483647dfsfgg123"));
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:25:33 by sohan             #+#    #+#             */
/*   Updated: 2021/04/06 02:47:22 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	result;
	int	n_power_of_ten;

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

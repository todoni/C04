/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:30:49 by sohan             #+#    #+#             */
/*   Updated: 2021/04/03 21:08:32 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_exception(int nb)
{
	if (nb == -2147483648)
	{
		nb = nb + 1;
		nb = -nb;
		write(1, "-", 1);
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	nbr[10];
	int		i;
	int		init;

	init = nb;
	nb = check_exception(nb);
	i = 0;
	while (nb != 0)
	{
		nbr[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	if (init == -2147483648)
	{
		nbr[0] = nbr[0] + 1;
	}
	while (i >= 1)
	{
		write(1, &nbr[i - 1], 1);
		i--;
	}
}

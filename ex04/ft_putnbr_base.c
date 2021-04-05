/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:41:36 by sohan             #+#    #+#             */
/*   Updated: 2021/04/05 20:44:07 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_exception(char *base)
{
	int exception;

	exception = 1;
	while (*base != 0)
	{
		if (*base - *(base + 1) == 0 || *base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (exception);
}

void	display_nbr_by_base(char *base, int nbr, int n)
{
	if (nbr == 0)
		return ;
	display_nbr_by_base(base, nbr / n, n);
	if (nbr < 0)
		write(1, &base[-(nbr % n)], 1);
	else
		write(1, &base[nbr % n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int n;
	
	n = 0;
	while (*base != '\0')
	{
		base++;
		n++;
	}
	base-= n;
	if (n == 1 || is_exception(base) == 0)
	{	
		return ;
	}
	else if (nbr == 0)
	{	
		write(1, &base[nbr % n], 1);
		return;
	}
	if (nbr < 0 && is_exception(base) != 0)
		write(1, "-", 1);
	if (is_exception(base) != 0)
		display_nbr_by_base(base, nbr, n);
}

int	main()
{
	ft_putnbr_base(-2147483648, "000");
	return 0;
}

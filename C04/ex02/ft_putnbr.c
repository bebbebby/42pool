/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:13:37 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/01 17:10:26 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putuint(unsigned int nb)
{
	if (nb > 9)
		ft_putuint(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	unsigned int	nb_abs;

	nb_abs = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nb_abs = ~0u - nb + 1;
	}
	ft_putuint(nb_abs);
}
#include <limits.h>

int main()
{
	ft_putnbr(INT_MAX);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-42);
	ft_putchar('\n');
	ft_putnbr(INT_MIN);
}
// void	ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	else if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		nb = -nb;
// 		ft_putnbr(nb);
// 	}
// 	else if (nb > 9)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// 	else
// 		ft_putchar(48 + nb);
// }

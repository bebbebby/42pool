/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:32:27 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/02 14:01:22 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2 || ft_strlen(base) == 0)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] <= 32 || base[i] > 126)
			return (0);
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putuint(unsigned int nb, unsigned int base_len, char *base)
{
	if (nb / base_len)
		ft_putuint(nb / base_len, base_len, base);
	ft_putchar(base[nb % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb_abs;

	if (check_base(base) == 0)
		return ;
	nb_abs = (unsigned int)nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb_abs = ~0u - nb_abs + 1;
	}
	ft_putuint(nb_abs, (unsigned int)ft_strlen(base), base);
}

// int main()
// {
// 	ft_putnbr_base(2335, "-01234567");
// }
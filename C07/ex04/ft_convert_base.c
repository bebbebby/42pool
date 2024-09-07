/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:02 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/07 18:04:58 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_base_len(char *base)
{
	int	i;
	int	j;

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
	return (i);
}

int	get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;

	if (get_base_len(base) < 2)
		return (0);
	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
			nb = -nb;
		}
		str++;
	}
	while (*str && get_val(*str, base) != -1)
	{
		nb = nb * ft_strlen(base) + get_val(*str, base);
		str++;
	}
	return (nb * sign);
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

	if (get_base_len(base) == 0)
		return ;
	nb_abs = (unsigned int)nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb_abs = ~0u - nb_abs + 1;
	}
	ft_putuint(nb_abs, (unsigned int)ft_strlen(base), base);
}


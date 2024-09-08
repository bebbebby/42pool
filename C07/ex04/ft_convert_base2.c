/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:05:24 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/08 07:58:32 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count_digits(unsigned int nb, int base_len)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count += 1;
		nb /= base_len;
	}
	return count;
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

void	convert(char *arr, int i, unsigned int nbr, char *base_to)
{
	while (i >= 0)
	{
		arr[i] = base_to[nbr % (unsigned int)get_base_len(base_to)];
		nbr = nbr / (unsigned int)get_base_len(base_to);
		i--;
	}
}

char	*itoa_base(int nb ,char *base_to)
{
	char *arr;
	int	i;
	unsigned int nbr;
	int	len;

	if (get_base_len(base_to) < 2)
		return (NULL);
	i = 0;
	nbr = (unsigned int)nb;
	if (nb < 0)
	{
		nbr = 1u - nbr - 1;
		len = count_digits(nbr, get_base_len(base_to)) + 1;
	}
	else
		len = count_digits(nbr, get_base_len(base_to));
	arr = malloc(sizeof(int) * (unsigned int)(len + 1));
	if (!arr)
		return (NULL);
	i = len - 1;
	arr[i + 1] = '\0';
	convert(arr, i, nbr ,base_to);
	if (nb < 0)
		arr[0] = '-';
	return (arr);
}

// int main()
// {
// 	int str = 123;
// 	char *pipi = itoa_base(str, "01");
// 	printf("%s" ,pipi);
// }
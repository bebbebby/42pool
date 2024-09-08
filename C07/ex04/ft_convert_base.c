/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:02 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/08 10:17:29 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_convert_base2.c"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	get_base_len(char *base)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (base[i])
// 	{
// 		if (base[i] == '+' || base[i] == '-')
// 			return (0);
// 		else if (base[i] <= 32 || base[i] > 126)
// 			return (0);
// 		j = 0;
// 		while (base[j])
// 		{
// 			if (i != j && base[i] == base[j])
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i);
// }

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

char	*itoa_base(int nb ,char *base_to);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	res;
	char *arr;

	if (get_base_len(base_from) < 2 || get_base_len(base_to) < 2)
		return (NULL);
	res = ft_atoi_base(nbr, base_from);
	arr = itoa_base(res, base_to);
	return (arr);
}

int main()
{
	char base_from[] = "0123456789";
	char arr[] = "45";
	char base_to[] = "01";

	printf("%s" ,ft_convert_base(arr, base_from, base_to));
}

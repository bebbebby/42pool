/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:02 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/08 10:52:25 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_base_len(char *base);
char	*itoa_base(int nb, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		res;
	char	*arr;

	if (get_base_len(base_from) < 2 || get_base_len(base_to) < 2)
		return (NULL);
	res = ft_atoi_base(nbr, base_from);
	arr = itoa_base(res, base_to);
	return (arr);
}

// #include "ft_convert_base2.c"
// #include <stdio.h>
// int main()
// {
// 	char base_from[] = "01";
// 	char arr[] = "11101010";
// 	char base_to[] = "0123456789";

// 	printf("%s" ,ft_convert_base(arr, base_from, base_to));
// }
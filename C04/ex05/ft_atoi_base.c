/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:02 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/01 21:56:31 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_val(char c ,char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return 0;
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sign;

	if (check_base(base) == 0)
		return (0);
	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			nb = -nb;
		}
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z'))
	{
		if (get_val(str[i] ,base))
		{
			nb = nb * ft_strlen(base) + get_val(str[i] ,base);
		}
		i++;
	}
	return (nb * sign);
}

#include <stdio.h>

int main()
{
	char arr[] = "12ab..a";
	char *base = "0123456789abcdef";

	int res = ft_atoi_base(arr, base);
	printf("%d" ,res);
}
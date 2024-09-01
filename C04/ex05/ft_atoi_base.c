/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:40:02 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/01 19:35:39 by hasbayou         ###   ########.fr       */
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

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;

	if (check_base(base) == 0)
		return (0);
	sign = 1;
	nb = 0;
	while (*str <= 32)
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
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * ft_strlen(base) + (base[*str - '0']);
		str++;
	}
	return (nb * sign);
}

// int main()
// {
// 	char arr[] = "---+12345";
// 	char *base = "0123456789abcdef";

// 	ft_atoi_base(arr, base);
// }
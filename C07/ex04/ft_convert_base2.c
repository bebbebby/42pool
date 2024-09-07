/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:05:24 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:52 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_convert_base.c"

int	ft_atoi_base(char *str, char *base);
// void	ft_putnbr_base(int nbr, char *base);
int	get_base_len(char *base);

char	*convert(int val ,char *base_to)
{
	int		len;
	char	*result;
	int 	nb;
	int		i;

	nb = val;
	len = 0;
	if (val == 0)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (nb < 0)
	{
		nb = -nb;
		len = nb + 1;
	}
	else
		len = nb;
	result = malloc(sizeof(int) * (len + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
		result[0] = '-';
	i = len + 1;
	result[i] = '\0';
	if (val < 0)
		i = 1;
	else
	 	i = 0;
	while (result[i])
	{
		result[i] = base_to[nb / get_base_len(base_to)];
		result[i] = base_to[nb % get_base_len(base_to)];
		i++;
	}
	return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (get_base_len(base_from) == 0 || get_base_len(base_to) == 0)
		return (NULL);
	int dval = ft_atoi_base(nbr, base_from);
	return convert(dval, base_to);
}

int main()
{
	char *str = "123";
	char *pipi = ft_convert_base(str, "0123456789", "10");
	printf("%s" ,pipi);
}
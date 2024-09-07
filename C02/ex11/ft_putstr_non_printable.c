/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:51:56 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/07 17:21:46 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_hex[] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(g_hex[(unsigned char)str[i] / 16]);
			ft_putchar(g_hex[(unsigned char)str[i] % 16]);
		}
		i++;
	}
}

// int main()
// {
// 	char str[] = {-12, 49 ,50 ,0};
// 	ft_putstr_non_printable(str);
// }

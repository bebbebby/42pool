/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:50:16 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/07 16:11:55 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_printcomsp(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	next_comb(char *str, int nb, int i)
{
	int	j;

	str[i] = str[i] + 1;
	j = i + 1;
	while (j < nb)
	{
		str[j] = str[j - 1] + 1;
		j++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = '0' + i;
		i++;
	}
	while (n)
	{
		i = 0;
		while (i < n)
			ft_putchar(tab[i++]);
		if (tab[0] != '9' - (n - 1))
			ft_printcomsp();
		i = n - 1;
		while (i >= 0 && tab[i] == '9' - (n - 1 - i))
			i--;
		if (i < 0)
			break ;
		next_comb(tab, n, i);
	}
}

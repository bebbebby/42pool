/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:02:46 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/03 12:05:00 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write (1, &str[i] ,1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i;

		i = 1;
		while (av[i])
		{
			ft_putstr(av[i]);
			write (1, "\n", 1);
			i++;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:15:52 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/03 14:49:26 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (av[j] && av[i])
	{
		while (ft_strcmp(av[i], av[j]) > 0)
		{
			ft_swap(&av[i], &av[j]);
			i = 1;
			j = i + 1;
		}
		j++;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		ft_sort(av);
		i = 1;
		while (av[i])
		{
			ft_putstr(av[i]);
			write (1, "\n", 1);
			i++;
		}
	}
}

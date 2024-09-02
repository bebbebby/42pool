/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:57:18 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/02 23:58:34 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 2)
		return (2);
	while (i < nb)
	{
		if (nb % i == 0)
			nb++;
		i++;
	}
	return (nb);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d", ft_find_next_prime(7));
// }
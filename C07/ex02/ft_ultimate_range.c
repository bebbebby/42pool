/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:04:47 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/04 17:08:07 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (unsigned int)(max - min));
	if (!tab)
	{
		*range = NULL;
		return (-1);
	}
	while (max > min)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}

// int main()
// {
// 	int k = 0;	      
// 	int max = 9;
// 	int min = 5;
// 	int *range;
// 	int i = ft_ultimate_range(&range, min, max);
// 	if (!range)
// 		return 0;
// 	// printf("%d" ,i);
// 	while (range[k])
// 	{
// 		printf("%d" ,range[k]);
// 		k++;
// 	}

// }
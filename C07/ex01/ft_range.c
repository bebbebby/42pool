/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:59:15 by hasbayou          #+#    #+#             */
/*   Updated: 2024/09/14 20:21:29 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*str;
	int		len;

	i = 0;
	len = max - min;
	if (min >= max)
		return (NULL);
	str = malloc(sizeof(int) * (unsigned int)len);
	if (!str)
		return (NULL);
	while (min < max)
	{
		str[i] = min++;
		i++;
	}
	return (str);
}

int main()
{
	int max = 9;
	int min = 5;
	int *range = ft_range(min, max);
	int i = 0;

	if (!range)
		return (0);
	while (range[i])
	{
		printf("%d" ,range[i]);
		i++;
	}
	free (range);
}
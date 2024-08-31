/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasbayou <hasbayou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:38:47 by hasbayou          #+#    #+#             */
/*   Updated: 2024/08/31 21:07:46 by hasbayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!to_find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
			j++;
		if (to_find[j] == 0)
			return (str + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char *str = "anass";
// 	char *to_find = "ass";

// 	printf("%s" ,ft_strstr(str, to_find));
// }
